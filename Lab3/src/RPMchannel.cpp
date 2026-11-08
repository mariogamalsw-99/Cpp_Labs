#include "RPMchannel.h"
#include <iostream>
RPMChannel::RPMChannel() : Channel()
{
}
RPMChannel::RPMChannel(unsigned int s) : Channel(s)
{
}
bool RPMChannel::readChannel(std::variant<int,float,double> &data)
{
    bool res = false;
    if (((readIndex + 1) % bufferSize) == writeIndex)
    {
        res = false;
    }
    else
    {
        // Shift read index
        readIndex++;
        readIndex %= bufferSize;
        // update data with read data from buffer
        data =std::get<int>( buffer[readIndex] );
        res = true;
        std::cout << "RPM Read: " << std::get<int> (data) << std::endl;
    }
    return res;
}
bool RPMChannel::writeChannel(std::variant<int,float,double> &data)
{
    bool res = false;
    if (readIndex == ((writeIndex + 1) % bufferSize))
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex] = std::get<int>(data);
        // Shift write index
        writeIndex++;
        writeIndex %= bufferSize;
        res = true;
        std::cout << "RPM Write: " << std::get<int>(data) << std::endl;
    }
    return res;
}