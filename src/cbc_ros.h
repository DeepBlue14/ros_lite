/**
 * File: cbc_ros.h
 * Author: James Kuczynskis
 * Email: jkuczyns@cs.uml.edu
 * File Description: 
 *
 * Refs: (printf) http://www.menie.org/georges/embedded/printf-stdarg.html
 *       (vfprintf) http://stackoverflow.com/questions/1719784/c-programming-forward-variable-argument-list
 *
 * Created: 2/18/2016
 * Last Modified: 2/26/2016 
 */


#ifndef CBC_ROS_H
#define CBC_ROS_H

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <printf.h>

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>

#include "cbc_sim.h"

using namespace std;

namespace cbc_ros
{
    class NodeHandle;
    class Subscriber;
    class Publisher;
    
    extern vector<void*> subscriberQueue; 
    extern vector<void*> publisherQueue;//motors and sensors are "nodes" we publish to
    //<topic_name, topic_queue_owner
    extern map<char*, Publisher*> topicMap;
    
    extern void queueInit();
    extern void init(bool analog_0_state, bool analog_1_state,
                     bool analog_2_state, bool analog_3_state,
                     bool analog_4_state, bool analog_5_state,
                     bool analog_6_state, bool analog_7_state);
    extern bool ok();
    extern void spin();
    extern void spinRate();
    extern char* rosTime();
    extern void ROS_INFO(const char* format, ...);
    extern void ROS_WARNING(const char* format, ...);
    extern void ROS_ERROR(const char* format, ...);
    extern void topicParser(const char* topic);
    
}


#endif /* CBC_ROS_H */
