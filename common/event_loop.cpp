#include "event_loop.h"

event_loop::event_loop(Json::Value config) {
    // get the config from the constructor and save it to the private variable
    this->_config               = config;
    // toggle the event loop to be true
    this->_event_loop_running   = true;
    // initialize the start time from config
    this->_start_time           = config["options"]["simulation_start_time"].asDouble();
    // initialize the start time to the current time
    this->_curr_time            = config["options"]["simulation_start_time"].asDouble();
    // initialize the end time from config
    this->_end_time             = config["options"]["simulation_end_time"].asDouble();
    // set the tick in the event loop
    this->_tick                 = config["options"]["simulation_tick"].asDouble();

}

void event_loop::run() {

    Logger& log = Logger::get("TestLogger");

    // conditions that monitors enables / disables 
    // through each tick
    while (this->_event_loop_running) { 
        
        // check if the current time is within the bounds of the simulation
        if (this->_curr_time > this->_end_time) {
            this->_event_loop_running = false;
            break;
        }

        //log.critical("simulation time: %f", this->_curr_time);

        // increment the curr_time by the tick
        this->_curr_time = this->_curr_time + this->_tick;


    }
    
}