#ifndef __EVENT_LOOP__
#define __EVENT_LOOP__

#include "Poco/Runnable.h"
#include "Poco/Logger.h"
#include <json/json.h>
#include <stdio.h>
#include <iostream>

using namespace std;

using Poco::Logger;

class event_loop :public Poco::Runnable{
    
    public:
        
        event_loop (Json::Value config);
        void run();

    private:
        
        Json::Value _config;
        bool _event_loop_running;
        double _start_time;
        double _curr_time;
        double _end_time;
        double _tick;
        
};

#endif