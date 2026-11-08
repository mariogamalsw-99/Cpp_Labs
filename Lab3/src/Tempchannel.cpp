#include "TempChannel.h"
#include <iostream>
TempChannel::TempChannel() : Channel()
{
}
TempChannel::TempChannel(unsigned int s) : Channel(s)
{
}
bool TempChannel::readChannel(std::variant<int,float,double> &data)
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
        data = std::get<double>(buffer[readIndex]);
        res = true;
        std::cout << "Temp Read: " << std::get<double>(data) << std::endl;
    }
    return res;
}
bool TempChannel::writeChannel(std::variant<int,float,double> &data)
{
    bool res = false;
    if (readIndex == ((writeIndex + 1) % bufferSize))
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex] = std::get<double>(data);
        // Shift write index
        writeIndex++;
        writeIndex %= bufferSize;
        res = true;
        std::cout << "Temp Write : " << std::get<double>(data) << std::endl;
    }
    return res;
}