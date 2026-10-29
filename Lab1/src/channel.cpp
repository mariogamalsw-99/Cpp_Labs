#include "channel.h"

Channel::Channel() : readIndex(0), writeIndex(1), bufferSize(20)
{
    buffer = new int[bufferSize];
}
Channel::Channel(unsigned int s) : readIndex(0), writeIndex(1), bufferSize(s)
{
    buffer = new int[s];
}
Channel::~Channel()
{
    delete[] buffer;
}
bool Channel::readChannel(int &data)
{
    bool res = false;
    if (((readIndex+1)%bufferSize) == writeIndex)
    {
        res = false;
    }
    else
    {
        // Shift read index
        readIndex++;
        readIndex %= bufferSize;
        // update data with read data from buffer
        data = buffer[readIndex];
        res = true;
    }
    return res;
}
bool Channel::writeChannel(int &data)
{
    bool res = false;
    if (readIndex == ((writeIndex + 1) % bufferSize))
    {
        res = false;
    }
    else
    {
        // update buffer with write data
        buffer[writeIndex] = data;
        // Shift write index
        writeIndex++;
        writeIndex %= bufferSize;
        res = true;
    }
    return res;
}