#include "server.h"
Server::Server(){

}
Server::~Server(){
    
}
// User Interface
bool Server::writeChannel(Channel_id_t id, int & data)
{
    bool res=false;
    if(id>=NUM_OF_CHANNELS)
    {
        res=false;
    }
    else
    {
        res=myChanneld[id].writeChannel(data);
    }
    return res;
}
Channel* Server::bindChannel(Channel_id_t id)
{
    return myChanneld+id;
}