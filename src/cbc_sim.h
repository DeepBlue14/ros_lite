/**
 * File: cbc_sim.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: This simulator serves as a safe test file to replace the
 *                   CBC-specific sysem calls. 
 *
 * Created: 2/17/2016
 * Last Modified: 2/25/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

extern int analog(int port);
extern int digital(int port);
extern void mav(int port, int velocity);
extern void motor(int port, int velocity);
extern void set_servo_position(int port, int velocity);
extern void set_each_analog_state(int port_0_status, int port_1_status,
                             int port_2_status, int port_3_status,
                             int port_4_status, int port_5_status,
                             int port_6_status, int port_7_status);
extern void cbc_printf(char* stringOfText);
extern int generateFakeData();
