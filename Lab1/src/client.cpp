#include "client.h"
Client::  Client(Server& s,Channel_id_t id)
{
    channelPtr= s.bindChannel(id);
}
Client::~Client(){
    
}
// User Interface
bool Client::clientRead(int& data)
{
    return channelPtr->readChannel(data);
}

