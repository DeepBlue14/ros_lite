/**
 * File: Subscriber.h
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


#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <queue>

#include "cbc_ros.h"

using namespace std;
using namespace cbc_ros;

class cbc_ros::Subscriber
{
    public:
        Subscriber();
        void poll();
        void setCallbackPtr(void* callbackPtr);
        void* getCallbackPtr();
        ~Subscriber();
            
            
    private:
        string topicStr;
        unsigned int msgQueueSize;
        queue<float>* msgQueuePtr;
        void* callbackPtr;
        pthread_t thread;
};

void* falsePrince(void* x);

#endif /* SUBSCRIBER_H */
