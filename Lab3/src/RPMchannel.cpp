#include "RPMchannel.h"
#include <iostream>
RPMChannel::RPMChannel() : Channel()
{
}
RPMChannel::RPMChannel(unsigned int s) : Channel(s)
{
}
bool RPMChannel::readChannel(data_t &data)
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
        data.intData = buffer[readIndex].intData;
        res = true;
        std::cout << "RPM Read: " << data.intData << std::endl;
    }
    return res;
}
bool RPMChannel::writeChannel(data_t &data)
{
    bool res = false;
    if (readIndex == ((writeIndex + 1) % bufferSize))
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex].intData = data.intData;
        // Shift write index
        writeIndex++;
        writeIndex %= bufferSize;
        res = true;
        std::cout << "RPM Write: " << data.intData << std::endl;
    }
    return res;
}