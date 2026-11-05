#ifndef RPM_CHANNEL_H
#define RPM_CHANNEL_H
#include "channel.h"
class RPMChannel : public Channel
{
private:


public:
    RPMChannel();
    RPMChannel(unsigned int s);
    virtual ~RPMChannel()=default;
    // User Interface
    virtual bool readChannel(data_t& data) override ;
    virtual bool writeChannel(data_t& data) override;
};

#endif