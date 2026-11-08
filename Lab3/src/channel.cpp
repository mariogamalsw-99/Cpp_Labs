#include "channel.h"

Channel::Channel() : readIndex(0), writeIndex(1), bufferSize(5)
{
    buffer = new std::variant<int,float,double>[bufferSize];
}
Channel::Channel(unsigned int s) : readIndex(0), writeIndex(1), bufferSize(s)
{
    buffer = new std::variant<int,float,double>[s];
}
Channel::~Channel()
{
    delete[] buffer;
}
