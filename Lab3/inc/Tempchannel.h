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
    virtual bool readChannel(data_t& data) override ;
    virtual bool writeChannel(data_t& data) override;
};

#endif