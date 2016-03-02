#include "Subscriber.h"

Subscriber::Subscriber()
{
    cbc_ros::subscriberQueue.push_back(callbackPtr);
    msgQueuePtr = new queue<float>();
    void* obj = reinterpret_cast<void*>(this);
    if(pthread_create(&thread, NULL, &falsePrince, obj) != 0 )
    {
        cerr << "ERROR: subscriber thread failed @ cbc_ros::Subscriber::Subscriber()" << endl;
    }
    //pthread_exit(NULL); // This would kill the parent
}


void Subscriber::poll()
{
    while(true)
    {
        if(msgQueuePtr->size() == msgQueueSize)
        {
            msgQueuePtr->pop();
        }

        msgQueuePtr->push(1.2); //analog10(2)
    }

    pthread_exit(NULL);
}


void Subscriber::setCallbackPtr(void* callbackPtr)
{
    this->callbackPtr = callbackPtr;
}


void* Subscriber::getCallbackPtr()
{
    return callbackPtr;
}
    
  
Subscriber::~Subscriber()
{
    ;
}


void* falsePrince(void* x)
{
    Subscriber* mySub = (Subscriber*)x;
    mySub->poll();
    
    return NULL;
}
