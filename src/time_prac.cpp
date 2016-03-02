/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: csrobot
 *
 * Created on February 26, 2016, 4:16 PM
 */

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <printf.h>


#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;


char* rosTime();


int main(int argc, char** argv)
{
    
    rosTime();
    
    return 0;
}


char* rosTime()
{
    time_t rawtime;
    struct tm* timeinfo;

    time( &rawtime );
    timeinfo = localtime( &rawtime );
    
    printf ( "Current local time and date: %s", asctime (timeinfo) );
    
    
    struct timeval tval_before, tval_after, tval_result;

    gettimeofday(&tval_before, NULL);

// Some code you want to time, for example:
    sleep(1);

    gettimeofday(&tval_after, NULL);

timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
}