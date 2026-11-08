#ifndef  SERVER_H
#define SERVER_H
#include "channel.h"
typedef enum
{
    SPEED,
    RPM,
    TEMP,
    NUM_OF_CHANNELS
}Channel_id_t;

class Server
{
    private:
    Channel* myChanneld[NUM_OF_CHANNELS];
    public:
    Server();
    ~Server();
    //User Interface
    bool writeChannel(Channel_id_t,std::variant<int,float,double>   & );
    Channel* bindChannel(Channel_id_t);
};

#endif