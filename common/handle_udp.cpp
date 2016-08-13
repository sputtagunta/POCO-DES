#include "handle_udp.h"

udp_server::udp_server(int port) {
    this->_port = port;
}

udp_server::~udp_server() {

}

void udp_server::run() {
    SocketAddress sa(IPAddress(), _port);
    DatagramSocket dgs(sa);
    SocketAddress sender;
    
    while(true) {
        string buffer;            
        int data_size = dgs.receiveFrom((char*)buffer.c_str(), sizeof(buffer)-1, sender);
        buffer[data_size] = '\0';
        thread_locker.lock();
        this->data_queue.push(buffer.substr(32, data_size));
        thread_locker.unlock();
    }
}

string udp_server::dequeue() {
    string response;

    if (!this->data_queue.empty()) {
        thread_locker.lock();
        response = this->data_queue.front();
        this->data_queue.pop();
        thread_locker.unlock();
    } else {
        response = "EMPTY";
    }

    return response;
}






