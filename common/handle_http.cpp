#include "handle_http.h"

using namespace std;


string data;

size_t write_callback(char* buf, size_t size, size_t nmemb, void* up) { 
    for (size_t c = 0; c<size*nmemb; c++) {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}

string get_url(string url) {
    CURL* curl; //our curl object

    curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_callback);
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

    curl_easy_perform(curl);

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return data;
}
