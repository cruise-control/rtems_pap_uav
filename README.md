rtems-paparazzi
===============

Port of the Paparazzi UAV autpilot source code to run on RTEMS.
This is a 'light touch' conversion where the cyclic nature of the embedded code is run on a single thread in RTEMS. RTEMS controls the timing (which is used for the cyclic scheduling) and both the UART and Ethernet Comms go through RTEMS. Currently the eclipse workspace is included as this simplifies development and modification of compile time variables (passed into the build system through an auto-generated make file).

Highlights

- Paparazzi UAV autopilot ported to RTEMS
- Setup for HIL usage
- Higher speed Uart
- Ethernet Comms added as a compile time settable transport mechanism
- Debug message path created (displays Autopilot debug messages on the PC side of the system)
- Tested and got to work for LEON3 and RPI development boards (both with RTEMS)

