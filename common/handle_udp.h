#ifndef __HANDLE_UDP__
#define __HANDLE_UDP__

#include <curl/curl.h>
#include <iostream>
#include <string>


#include <string>
#include <fstream>
#include <streambuf>
#include <json/json.h>
#include <sstream>

#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;
using namespace Poco::Net;

class udp_server: public Poco::Runnable {
    private:
        int _port;
        queue<string> data_queue;
        Poco::Mutex thread_locker;
    public:
        udp_server(int port);
        ~udp_server();
        void run();
        string dequeue();
};


class udp_client: public Poco::Runnable {
    private:
        Poco::Mutex thread_locker;
    public:
        udp_client(string host, int port);
        ~udp_client();
        void send_message(string buffer, int data_size);
};


#endif