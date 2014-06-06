/*
 * Copyright (C) 2010-2013 The Paparazzi Team
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * @file subsystems/electrical.c
 *
 * Implemnetation for electrical status: supply voltage, current, battery status, etc.
 */

#include "subsystems/electrical.h"

#include "mcu_periph/adc.h"
#include "subsystems/commands.h"

#include "generated/airframe.h"
#include BOARD_CONFIG

#ifdef MILLIAMP_PER_PERCENT
#warning "deprecated MILLIAMP_PER_PERCENT --> Please use MILLIAMP_AT_FULL_THROTTLE"
#endif
#if defined BATTERY_SENS || defined BATTERY_OFFSET
#warning "BATTERY_SENS and BATTERY_OFFSET are deprecated, please remove them --> if you want to change the default use VoltageOfAdc"
#endif

#if defined COMMAND_THROTTLE
#define COMMAND_CURRENT_ESTIMATION COMMAND_THROTTLE
#elif defined COMMAND_THRUST
#define COMMAND_CURRENT_ESTIMATION COMMAND_THRUST
#endif

#ifndef BAT_CHECKER_DELAY
#define BAT_CHECKER_DELAY 5
#endif

#define ELECTRICAL_PERIODIC_FREQ 10

PRINT_CONFIG_VAR(LOW_BAT_LEVEL)
PRINT_CONFIG_VAR(CRITIC_BAT_LEVEL)

struct Electrical electrical;

#if defined ADC_CHANNEL_VSUPPLY || defined ADC_CHANNEL_CURRENT || defined MILLIAMP_AT_FULL_THROTTLE
static struct {
#ifdef ADC_CHANNEL_VSUPPLY
  struct adc_buf vsupply_adc_buf;
#endif
#ifdef ADC_CHANNEL_CURRENT
  struct adc_buf current_adc_buf;
#endif
#ifdef MILLIAMP_AT_FULL_THROTTLE
  float nonlin_factor;
#endif
} electrical_priv;
#endif

#ifndef VoltageOfAdc
#define VoltageOfAdc(adc) DefaultVoltageOfAdc(adc)
#endif
#ifndef MilliAmpereOfAdc
#define MilliAmpereOfAdc(adc) DefaultMilliAmpereOfAdc(adc)
#endif

#ifndef CURRENT_ESTIMATION_NONLINEARITY
#define CURRENT_ESTIMATION_NONLINEARITY 1.2
#endif

void electrical_init(void) {
  electrical.vsupply = 0;
  electrical.current = 0;
  electrical.energy = 0;

  electrical.bat_low = FALSE;
  electrical.bat_critical = FALSE;

#if defined ADC_CHANNEL_VSUPPLY
  adc_buf_channel(ADC_CHANNEL_VSUPPLY, &electrical_priv.vsupply_adc_buf, DEFAULT_AV_NB_SAMPLE);
#endif

  /* measure current if available, otherwise estimate it */
#if defined ADC_CHANNEL_CURRENT && !defined SITL
  adc_buf_channel(ADC_CHANNEL_CURRENT, &electrical_priv.current_adc_buf, DEFAULT_AV_NB_SAMPLE);
#elif defined MILLIAMP_AT_FULL_THROTTLE
PRINT_CONFIG_VAR(CURRENT_ESTIMATION_NONLINEARITY)
  electrical_priv.nonlin_factor = CURRENT_ESTIMATION_NONLINEARITY;
#endif
}

void electrical_periodic(void) {
  static uint8_t bat_low_counter = 0;
  static uint8_t bat_critical_counter = 0;

#if defined(ADC_CHANNEL_VSUPPLY) && !defined(SITL)
  electrical.vsupply = 10 * VoltageOfAdc((electrical_priv.vsupply_adc_buf.sum/electrical_priv.vsupply_adc_buf.av_nb_sample));
#endif

#ifdef ADC_CHANNEL_CURRENT
#ifndef SITL
  electrical.current = MilliAmpereOfAdc((electrical_priv.current_adc_buf.sum/electrical_priv.current_adc_buf.av_nb_sample));
  /* Prevent an overflow on high current spikes when using the motor brake */
  BoundAbs(electrical.current, 65000);
#endif
#elif defined MILLIAMP_AT_FULL_THROTTLE && defined COMMAND_CURRENT_ESTIMATION
  /*
   * Superellipse: abs(x/a)^n + abs(y/b)^n = 1
   * with a = 1
   * b = mA at full throttle
   * n = 1.2     This defines nonlinearity (1 = linear)
   * x = throttle
   * y = current
   *
   * define CURRENT_ESTIMATION_NONLINEARITY in your airframe file to change the default nonlinearity factor of 1.2
   */
  float b = (float)MILLIAMP_AT_FULL_THROTTLE;
  float x = ((float)commands[COMMAND_CURRENT_ESTIMATION]) / ((float)MAX_PPRZ);
  /* electrical.current y = ( b^n - (b* x/a)^n )^1/n
   * a=1, n = electrical_priv.nonlin_factor
   */
  electrical.current = b - pow((pow(b,electrical_priv.nonlin_factor)-pow((b*x),electrical_priv.nonlin_factor)), (1./electrical_priv.nonlin_factor));
#endif /* ADC_CHANNEL_CURRENT */

  // mAh = mA * dt (10Hz -> hours)
  electrical.energy += ((float)electrical.current) / 3600.0f / ELECTRICAL_PERIODIC_FREQ;

  if (electrical.vsupply < LOW_BAT_LEVEL * 10) {
    if (bat_low_counter > 0)
      bat_low_counter--;
    if (bat_low_counter == 0)
      electrical.bat_low = TRUE;
  }
  else {
    // reset battery low status and counter
    bat_low_counter = BAT_CHECKER_DELAY * ELECTRICAL_PERIODIC_FREQ;
    electrical.bat_low = FALSE;
  }

  if (electrical.vsupply < CRITIC_BAT_LEVEL * 10) {
    if (bat_critical_counter > 0)
      bat_critical_counter--;
    if (bat_critical_counter == 0)
      electrical.bat_critical = TRUE;
  }
  else {
    // reset battery critical status and counter
    bat_critical_counter = BAT_CHECKER_DELAY * ELECTRICAL_PERIODIC_FREQ;
    electrical.bat_critical = FALSE;
  }

}
