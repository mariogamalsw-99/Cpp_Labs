#ifndef TEMP_CHANNEL_H
#define TEMP_CHANNEL_H
#include "channel.h"
class TempChannel : public Channel
{
private:


public:
    TempChannel();
    TempChannel(unsigned int s);
    virtual ~TempChannel()=default;
    // User Interface
    virtual bool readChannel(std::variant<int,float,double>& data) override ;
    virtual bool writeChannel(std::variant<int,float,double>& data) override;
};

#endif