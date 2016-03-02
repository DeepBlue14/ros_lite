/**
 * File: NodeHandle.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 *
 * Refs: http://www.cplusplus.com/forum/beginner/6596/
 *
 * Created: 2/17/2016
 * Last Modified: 2/25/2016
 */


#ifndef NODE_HANDLE_H
#define NODE_HANDLE_H

#include <string>
#include <iostream>

#include "Subscriber.h"
#include "Publisher.h"
#include "cbc_ros.h"

using namespace std;
using namespace cbc_ros;

class cbc_ros::NodeHandle
{
    public:
        NodeHandle() {}
        
        template<typename X>
        Subscriber subscribe(const char* topicStr, unsigned int msgQueueSize, void(*callbackPtr)(float))
        {
            cout << "................and....................." << endl;
            Subscriber sub;
            
            //sub.setCallbackPtr(callbackPtr);
            cout << subscriberQueue.size() << endl;
            subscriberQueue.push_back((void*)callbackPtr);
            /*void (*foo)(int);
            //foo = callbackPtr;
            cout << subscriberQueue.size() << endl;
            cout << callbackPtr << endl;
            cout << subscriberQueue.at(1) << endl;
            foo = subscriberQueue.at(1);
            foo( 2 );
            (*foo)( 2 );
            */
            return sub;
        }
        
        template<typename X>
        Publisher advertise(const char* topicStr, unsigned int msgQueueSize)
        {
            Publisher pub;
            
            return pub;
        }

        ~NodeHandle() {}
        
    private:
        ;
};


#endif /* NODE_HANDLE_H */
