#include "SpeedChannel.h"
#include <iostream>
SpeedChannel::SpeedChannel() : Channel()
{
}
SpeedChannel::SpeedChannel(unsigned int s) : Channel(s)
{
}
bool SpeedChannel::readChannel(std::variant<int,float,double> &data)
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
        data = std::get<float>(buffer[readIndex]);
        res = true;
        std::cout << "Speed Read: " << std::get<float>(data) << std::endl;
    }
    return res;
}
bool SpeedChannel::writeChannel(std::variant<int,float,double> &data)
{
    bool res = false;
    if (readIndex == ((writeIndex + 1) % bufferSize))
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex] = std::get<float>(data);
        // Shift write index
        writeIndex++;
        writeIndex %= bufferSize;
        res = true;
        std::cout << "Speed Write : " << std::get<float>(data) << std::endl;
    }
    return res;
}