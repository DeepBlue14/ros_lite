#include "Publisher.h"


Publisher::Publisher()
{
    if(subscriberQueue.size() == 0)
    {
        queueInit();
    }
    port = 0; //FIXME: un-hard code this; parse it from the topic
    ringCounter = 0;
    //typedef void(*fptr)(float);
    cout << "HERE (0) queue size:" << publisherQueue.size() << endl;
    my_fptr = reinterpret_cast<fptr>(publisherQueue.at(ringCounter) );
    cout << "HERE (1)" << endl;
    //my_fptr( 5.4 );
}


void Publisher::publish(int msg)
{
    //mav(sensor_port, msg);
    my_fptr(port, msg);
}
    
    
Publisher::~Publisher()
{
    ;
}

