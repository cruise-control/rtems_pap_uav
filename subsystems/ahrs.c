/*
 * Copyright (C) 2008-2010 The Paparazzi Team
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
 * @file subsystems/ahrs.c
 * Attitude and Heading Reference System interface.
 */


#include "subsystems/ahrs.h"

struct Ahrs ahrs;

#define WEAK __attribute__((weak))
// weak functions, used if not explicitly provided by implementation

//SC Making sure this is not getting called, unsure if compiler properly supports it
//void WEAK ahrs_propagate(void) {}

//void WEAK ahrs_update_accel(void) {}

void WEAK ahrs_update_mag(void) {}

void WEAK ahrs_update_gps(void) {}
