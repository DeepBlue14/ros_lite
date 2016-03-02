#ros_lite

*A reimplementation of ROS for the CBC Botball controller*

*Author/Maintainer:* James Kuczynski,  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Undergraduate Researcher,  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Robotics Laboratory, 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;University of Massachusetts Lowell.  
*Email:* jkuczyns@cs.uml.edu

=====


###**Project Synopsis**

This is a reimplementation of ROS to run natively on the CBC Botaball controllers, or on other devices with similar processing or network limitations.  This version is designed for the CBC "v2", which does not have internet copacities.


###**Introduction**

This project adds a level of abstraction to the development process, allowing the user to run ROS-like code on a CBC or other basic processing unit.  It also allows users to easily develop multi-threaded programs without the hastle of manually using the pthead library.  Similar to ROS, this project uses a subscribe/publish paradigm.

This project could be used as a gentle introduction to ROS and multithreading for children.


Sample code:
```c++
#include <iostream>

#include "cbc_ros.h"
#include "NodeHandle.h"
#include "Subscriber.h"
#include "Publisher.h"
#include "cbc_ros.cpp"      /* The KISS IDE does not allow direct access to
#include "Subscriber.cpp"    * a Makefile, so source files must be linked
#include "Publisher.cpp"     * against explicitly.  Yeah, it's a gross
                             * solution, but blame the folks who wrote
                             * the IDE, not me.
                             */
using namespace std;

void callback(float msg)
{

    cout << "@@@ callback(...): " << msg << endl;
    //pthread_exit(NULL); // This would kill the parent
}


int main(int argc, char **argv)
{
    cout << "Hello CBC!" << endl;
    cbc_ros::NodeHandle nh;
    cout << "about to create subscriber @ main()" << endl;
    cbc_ros::Subscriber sub = nh.subscribe<int>("/analog/2",
                                  10,
                                  (void*)callback);



    cbc_ros::spin();
    
    cout << "Goodbye from main()" << endl;

    return 0;
}

```


###**Dependencies**

- Linux header files
- STD
- g++


###**Build & Run**

To run the sample code, go to the directory "ros_lite".
Run
```
make
./Test.exe
```


###**Future Work**

*TBA...*
