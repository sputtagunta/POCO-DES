#ifndef __HANDLE_CONFIG__
#define __HANDLE_CONFIG__

/*** 3rd party code ***/
#include <string>
#include <fstream>
#include <streambuf>
#include <json/json.h>


#include "handle_http.h"

using namespace std;

Json::Value read_config(string config_path);
Json::Value read_config_file(string config_path);
Json::Value read_config_url(string config_url);

#endif