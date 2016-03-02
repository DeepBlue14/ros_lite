#include <iostream>

#include "cbc_ros.h"
#include "NodeHandle.h"
#include "Subscriber.h"
#include "Publisher.h"
#include "cbc_ros.cpp"
#include "Subscriber.cpp"
#include "Publisher.cpp"

#include "cbc_sim.h"

using namespace std;

Publisher servoPub;
int sonarReadingArr[] = {0, 0, 0, 0, 0};
int currIndex = 0;
int servoPosArr[] = {5, 455, 905, 1355, 1805};
bool isInc = 1;

void callback(float msg)
{
    ROS_INFO("@callback(...) msg: %f\n", msg);
    sonarReadingArr[currIndex] = (int)msg;
    if(currIndex == 4)
        isInc = 0;
    else if(currIndex == 0)
        isInc = 1;
        
    if(isInc)
        currIndex++;
    else
        currIndex--;
        
    cout << "index: " << currIndex << ", " << servoPosArr[currIndex] << endl;
    set_servo_position(0, servoPosArr[currIndex]);
    sleep(2.0);
    
    //get the current best direction
    int bestIndex = -1;
    int bestVal = -1;
    for(int i = 0; i < 5; i++)
    {
        if(sonarReadingArr[i] > bestVal)
        {
            bestVal = sonarReadingArr[i];
            bestIndex = i;
        }
    }
    //rotate
    
    //after rotating, drive forward
    mav(0, 400);
    mav(3, 400);
}


int main(int argc, char **argv)
{
    cout << "Hello CBC!" << endl;
    init(1, 0, 0, 0, 0, 0, 0, 0);
    //cout << rosTime() << endl;
    NodeHandle nh;
    
    //subscribe to analog(0), i.e. the sonar sensor
    Subscriber sub = nh.subscribe<int>("/analog_0/recv",
                                       5,
                                       callback);
    
    //publisher data to set_servo_position(msg) i.e. the servo
    servoPub = nh.advertise<int>("/servo_0/send",
                                 1);
                                 
    
    
                                      
    spin();
    
    cout << "Goodye from main()" << endl;
    
    return 0;
}
