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

Publisher pub;

void callback(float msg)
{
    //cout << "@callback(...): " << msg << endl;
    pub.publish(msg);
    ROS_INFO("@callback(...): %f\n", msg);
    //cout << "successfully called .publish(...)" << endl;
}


int main(int argc, char **argv)
{
    cout << "Hello CBC!" << endl;
    init(1, 0, 0, 0, 0, 0, 0, 0);
    //cout << rosTime() << endl;
    NodeHandle nh;
    cout << "about to create subscriber @main()" << endl;
    Subscriber sub = nh.subscribe<int>("/analog/2",
                                       10,
                                       callback);
                                       
    pub = nh.advertise<int>("/motor/0",
                            10);
                                      
    spin();
    
    cout << "Goodye from main()" << endl;
    
    return 0;
}
