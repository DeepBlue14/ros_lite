#include "cbc_ros.h"

namespace cbc_ros
{
    vector<void*> publisherQueue;
    vector<void*> subscriberQueue;
    map<char*, Publisher*> topicMap;


    void queueInit()
    {
        //TODO: this may break Subscriber------
        publisherQueue.push_back((void*)mav);
        publisherQueue.push_back((void*)motor);
        //-------------------------------------
    }


    void init(bool analog_0_state, bool analog_1_state,
                     bool analog_2_state, bool analog_3_state,
                     bool analog_4_state, bool analog_5_state,
                     bool analog_6_state, bool analog_7_state)
    {
        cout << "@cbc_ros::init(...) starting" << endl;
        set_each_analog_state(analog_0_state, analog_1_state,
                          analog_2_state, analog_3_state,
                          analog_4_state, analog_5_state,
                          analog_6_state, analog_7_state);
        sleep(0.4);
        
        cout << "@cbc_ros::init(...) finished" << endl;
    }
                     
    
    
    bool ok()
    {
        ;
    }

    void spin()
    {
        //sleep(1.0);
        int ringCounter = 1;
        while(true)
        {
            if(subscriberQueue.size() > 1)
            {
                //cout << "calling callback" << endl;
                
                /*
                void (*foo)(float);
                cout << subscriberQueue.at(ringCounter) << endl;
                foo = subscriberQueue.at(ringCounter);
                foo( 5.4 );
                */
                typedef void(*fptr)(float);
                fptr my_fptr = reinterpret_cast<fptr>(subscriberQueue.at(ringCounter) );
                my_fptr( analog(6) ); //FIXME: un-hard code this
                //*reinterpret_cast<void**>(&my_ptr)
                
                if(ringCounter < subscriberQueue.size()-1 )
                {
                    ringCounter++;
                }
                else
                {
                    ringCounter = 1;
                }
            }
            else
            {
                cout << "@ cbc_ros::spin() queue is empty" << endl;
            }

        }
    }
    
    
    void spinRate()
    {
        ;
    }
    
    
    char* rosTime()
    {
        time_t rawtime;
        struct tm* timeinfo;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        printf ( "Current local time and date: %s", asctime (timeinfo) );
    }
    
    
    void ROS_INFO(const char* format, ...)
    {
        string tmp("");
        tmp.append(format);
        tmp.append("\033[0m");
        const char* res = tmp.c_str();
        
        va_list args;
        va_start(args, format);
        vfprintf(stdout, res, args);
    }
    
    
    void ROS_WARNING(const char* format, ...)
    {
        string tmp("\033[0;33m");
        tmp.append(format);
        tmp.append("\033[0m");
        const char* res = tmp.c_str();
        
        va_list args;
        va_start(args, format);
        vfprintf(stdout, res, args);
    }
    
    
    void ROS_ERROR(const char* format, ...)
    {
        string tmp("\033[0;31m");
        tmp.append(format);
        tmp.append("\033[0m");
        const char* res = tmp.c_str();
        
        va_list args;
        va_start(args, format);
        vfprintf(stderr, res, args);
    }
    
    
    void topicParser(const char* topic)
    {
        string str(topic);
        
        int pos = str.find("/analog");
        if(pos != -1)
        {
            char port = str.at(8);
        }
    }
    
    
    
    



}
