#ifndef  CLIENT_H
#define CLIENT_H
#include "server.h"

class Client
{
    private:
    Channel myChanneld[NUM_OF_CHANNELS];
    public:
    Client();
    ~Client();
    //User Interface
    bool writeChannel(Channel_id_t,int& );
    Channel* bindChannel(Channel_id_t);
};

#endif