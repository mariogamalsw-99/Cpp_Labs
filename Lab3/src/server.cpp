#include "server.h"
#include "RPMchannel.h"
#include "Speedchannel.h"
#include "Tempchannel.h"
Server::Server()
{
    for (int i = 0; i < NUM_OF_CHANNELS; i++)
    {
        switch (i)
        {
        case SPEED:
            myChanneld[i] = new SpeedChannel();
            break;
        case RPM:
            myChanneld[i] = new RPMChannel();
            break;
        case TEMP:
            myChanneld[i] = new TempChannel();
            break;
        default:
            break;
        }
    }
}
Server::~Server()
{
    for (int i = 0; i < NUM_OF_CHANNELS; i++)
        delete myChanneld[i];
}
// User Interface
bool Server::writeChannel(Channel_id_t id, std::variant<int,float,double> &data)
{
    bool res = false;
    if (id >= NUM_OF_CHANNELS)
    {
        res = false;
    }
    else
    {
        res = myChanneld[id]->writeChannel(data);
    }
    return res;
}
Channel *Server::bindChannel(Channel_id_t id)
{
    return *(myChanneld + id);
}