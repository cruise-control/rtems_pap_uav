rtems-paparazzi
===============

Port of the Paparazzi UAV autopilot source code to run on RTEMS.
This is a 'light touch' conversion where the cyclic nature of the embedded code is run on a single thread in RTEMS. RTEMS controls the timing (which is used for the cyclic scheduling) and both the UART and Ethernet Comms go through RTEMS. Currently the eclipse workspace is included as this simplifies development and modification of compile time variables (passed into the build system through an auto-generated make file). Also, the auto-generated build folder is included which (with the correct environment setup) can be run immediately.

The goal of this project was to make a first step in creating a base platform for dynamic simulation testing on a remote development board. Following the successful integration of this work with the Papparazzi UAV GCS & Server, a Java version of the project is the next phase. The Java version will also run on RTEMS and (ideally) behave in a similar manner as the C version but it will have real-time compliant tasks instead of cyclic scheduling. Search the internet for RTDroid to get more information on the projects.

Note: This project was created for academic research purposes and there is much work that could still be done to improve it.

Highlights

- Paparazzi UAV autopilot ported to RTEMS
- Setup for HIL usage
	- NPS data sent to the autopilot over a chosen communication channel
	- Data fed into the Autopilot in such a way as to mimic real-flight
	- Autopilot has minimal hardware connectivity but processes data and generates control surface commands as if it was real-flight
- Higher speed Uart
- Ethernet Comms added as a compile time settable transport mechanism
- Debug message path created (displays Autopilot debug messages on the PC side of the system)
- Tested and got to work for LEON3 and RPI development boards (both with RTEMS)

