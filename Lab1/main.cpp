#include <iostream>
#include "channel.h"


int main()
{
    Channel mychannel{10};
    int x=10;
    mychannel.writeChannel(x);
    x=77;
    mychannel.writeChannel(x);
    mychannel.readChannel(x);
    std::cout<<"first written data: "<<x<<std::endl;
    mychannel.readChannel(x);
    std::cout<<"second written data: "<<x<<std::endl;
    mychannel.readChannel(x);
    std::cout<<"third written data: "<<x<<std::endl;
    return 0;
}