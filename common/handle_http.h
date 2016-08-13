#ifndef __HANDLE_HTTP__
#define __HANDLE_HTTP__

#include <curl/curl.h>
#include <iostream>
#include <string>


#include <string>
#include <fstream>
#include <streambuf>
#include <json/json.h>
#include <sstream>

using namespace std;

size_t write_callback(char* buf, size_t size, size_t nmemb, void* up);
string get_url(string url);


#endif