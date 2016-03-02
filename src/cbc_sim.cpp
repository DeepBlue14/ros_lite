#include "cbc_sim.h"


int analog(int port)
{
    printf("@ cbc_sim::analog(%d)\n", port);
    sleep(0.1); // Simulates the actual time required to get the data
    return generateFakeData();
}


int digital(int port)
{
    printf("@cbc_sim::digital(%d)\n", port);
    
    return generateFakeData();
}


void mav(int port, int velocity)
{
    printf("@mav(%d, %d)\n", port, velocity);
}


void motor(int port, int velocity)
{
    printf("@motor(%d, %d)\n", port, velocity);
}


void set_servo_position(int port, int velocity)
{
    printf("@set_servo_position(%d, %d)\n", port, velocity);
}


void set_each_analog_state(int port_0_status, int port_1_status,
                      int port_2_status, int port_3_status,
                      int port_4_status, int port_5_status,
                      int port_6_status, int port_7_status)
{
    printf("@set_analog_ports(%d, %d, %d, %d, %d, %d, %d, %d)\n", port_0_status, port_1_status, port_2_status, 
                                                                port_3_status, port_4_status, port_5_status, 
                                                                port_6_status, port_7_status);
}


void cbc_printf(char* stringOfText)
{
    printf("@cbc_printf(%s)\n", stringOfText);
}


int generateFakeData()
{
    srand(time(NULL));
    return (rand() % 1000);// range from 0 to 999
}
    
