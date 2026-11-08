#ifndef SPEED_CHANNEL_H
#define SPEED_CHANNEL_H
#include "channel.h"
class SpeedChannel : public Channel
{
private:


public:
    SpeedChannel();
    SpeedChannel(unsigned int s);
    virtual ~SpeedChannel()=default;
    // User Interface
    virtual bool readChannel(std::variant<int,float,double>& data) override ;
    virtual bool writeChannel(std::variant<int,float,double>& data) override;
};

#endif