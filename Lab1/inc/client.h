#ifndef  CLIENT_H
#define CLIENT_H
#include "channel.h"
#include "server.h"

class Client
{
    private:
    Channel* channelPtr;
    public:
    Client(Server&,Channel_id_t );
    ~Client();
    //User Interface
    bool clientRead(int& );

};

#endif