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
    virtual bool readChannel(data_t& data) override ;
    virtual bool writeChannel(data_t& data) override;
};

#endif