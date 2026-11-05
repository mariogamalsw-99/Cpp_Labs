#include "SpeedChannel.h"
#include <iostream>
SpeedChannel::SpeedChannel() : Channel()
{
}
SpeedChannel::SpeedChannel(unsigned int s) : Channel(s)
{
}
bool SpeedChannel::readChannel(data_t &data)
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
        data.floatData = buffer[readIndex].floatData;
        res = true;
        std::cout << "Speed Read: " << data.floatData << std::endl;
    }
    return res;
}
bool SpeedChannel::writeChannel(data_t &data)
{
    bool res = false;
    if (readIndex == ((writeIndex + 1) % bufferSize))
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex].floatData = data.floatData;
        // Shift write index
        writeIndex++;
        writeIndex %= bufferSize;
        res = true;
        std::cout << "Speed Write : " << data.floatData << std::endl;
    }
    return res;
}