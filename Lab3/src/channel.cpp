#include "channel.h"

Channel::Channel() : readIndex(0), writeIndex(1), bufferSize(5)
{
    buffer = new data_t[bufferSize];
}
Channel::Channel(unsigned int s) : readIndex(0), writeIndex(1), bufferSize(s)
{
    buffer = new data_t[s];
}
Channel::~Channel()
{
    delete[] buffer;
}
