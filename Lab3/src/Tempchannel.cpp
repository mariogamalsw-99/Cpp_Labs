#include "TempChannel.h"
#include <iostream>
TempChannel::TempChannel() : Channel()
{
}
TempChannel::TempChannel(unsigned int s) : Channel(s)
{
}
bool TempChannel::readChannel(data_t &data)
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
        data.doubleData = buffer[readIndex].doubleData;
        res = true;
        std::cout << "Temp Read: " << data.doubleData << std::endl;
    }
    return res;
}
bool TempChannel::writeChannel(data_t &data)
{
    bool res = false;
    if (readIndex == ((writeIndex + 1) % bufferSize))
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex].doubleData = data.doubleData;
        // Shift write index
        writeIndex++;
        writeIndex %= bufferSize;
        res = true;
        std::cout << "Temp Write : " << data.doubleData << std::endl;
    }
    return res;
}