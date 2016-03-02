// Created on Mon Feb 15 2016

#include <unistd.h>
#include <cstdlib>
#include <iostream>

#define NUM_THREADS	5

using namespace std;

int main() 
{
	cout << "Hello, World!" << endl;
	
	pid_t pidArr[NUM_THREADS];
	pidArr[0] = getpid();
	

	pidArr[1] = fork();

	
	
	
    if(getpid() != pidArr[0])
	{
    	cout << "I am child: " << getpid() << " --goodbye!" << endl;
		exit(0);
	}
	
	
	return 0;
}
