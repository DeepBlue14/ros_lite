/**
 * File: Publisher.h
 * Author: James Kuczynski
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 *
 * Created: 2/17/2016
 * Last Modified: 2/25/2016
 */


#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "cbc_ros.h"

using namespace std;
using namespace cbc_ros;

typedef void(*fptr)(int, float);
fptr my_fptr;

class cbc_ros::Publisher
{
    public:
        Publisher();
        void publish(int msg);
        ~Publisher();
            
            
    private:
        int ringCounter;
        string topicStr;
        int port;
        unsigned int msgQueueSize;
        char* callbackAddr;
};

#endif /* PUBLISHER_H */
