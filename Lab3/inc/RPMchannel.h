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
    virtual bool readChannel(std::variant<int,float,double>& data) override ;
    virtual bool writeChannel(std::variant<int,float,double>& data) override;
};

#endif