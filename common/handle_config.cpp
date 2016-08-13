#include "handle_config.h"


Json::Value read_config(string config_path) {
    // determine if config_path is filepath or url
    size_t found = config_path.find("http");
    if (found!=string::npos) {
        string config_url = config_path;
        return read_config_url(config_url);
    } else {
        return read_config_file(config_path);
    }
}

Json::Value read_config_file(string config_path) {
    
    /*** read file into string ***/
    // create input file stream
    ifstream file_ptr(config_path.c_str());
    // read file contents into string file_contents
    string file_contents((istreambuf_iterator<char>(file_ptr)), 
        istreambuf_iterator<char>());
    // convert string into json

    /*** convert string to Json::Value ***/
    Json::Value config;
    Json::Reader reader;
    bool parsing_successful = reader.parse( file_contents, config );
    if ( !parsing_successful ) {
        // report to the user the failure and their 
        // locations in the document.
        cout  << "Failed to parse configuration\n";
    }

    return config;
}

Json::Value read_config_url(string config_url) {
    /*** read file from url ***/
    string http_response = get_url(config_url);
    /*** convert http_response to Json::Value ***/
    Json::Value config;
    Json::Reader reader;
    bool parsing_successful = reader.parse( http_response, config );
    if ( !parsing_successful ) {
        // report to the user the failure and their 
        // locations in the document.
        cout  << "Failed to parse configuration\n";
    }
    
    return config;
}