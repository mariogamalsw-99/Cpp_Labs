#include <iostream>
#include "channel.h"
#include "server.h"
#include "client.h"

int main()
{
    Server myServer{};
    bool isOk = true;
    data_t data ;
    data.intData=-5;
    //write in channels
    for (int i = 0; i < 5; i++)
    {
        data.floatData=i+1;
        isOk = myServer.writeChannel(SPEED, data);
        if (isOk)
        {
            // std::cout <<i<< ". WRITE " << data << " TO Speed Channel."<<std::endl;
        }
        else
        {
            std::cout <<i<< ". COULDN'T WRITE " << " TO Speed Channel."<<std::endl;
        }
        data.intData=i+20;
        isOk = myServer.writeChannel(RPM, data);
        if (isOk)
        {
            // std::cout<<i << ". WRITE " << data << " TO RPM Channel."<<std::endl;
        }
        else
        {
            std::cout<<i << ". COULDN'T WRITE " << i << " TO RPM Channel."<<std::endl;
        }
        data.doubleData=89.089+i;
        isOk = myServer.writeChannel(TEMP, data);
        if (isOk)
        {
            // std::cout<<i << ". WRITE " << data << " TO TEMP Channel."<<std::endl;
        }
        else
        {
            std::cout <<i << ". COULDN'T WRITE " <<  " TO TEMP Channel."<<std::endl;
        }
    }
    Client speedClient(myServer,SPEED);
    Client rpmClient(myServer,RPM);
    Client tempClient(myServer,TEMP);
    for(int i=0;i<8;i++)
    {
        isOk=speedClient.clientRead(data);
        if(isOk)
        {
            // std::cout<<i<<".SpeedClient read "<<data<<std::endl;
        }
        else
        {
            std::cout<<i<<".SpeedClient couldn't read "<<std::endl;
        }
    }
    return 0;
}