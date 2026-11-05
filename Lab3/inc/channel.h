#ifndef CHANNEL_H
#define CHANNEL_H
// #include <variant>
// std::variant<int,float,double> data_t;
union data_t
{
    int intData;
    float floatData;
    double doubleData;
};


class Channel
{
protected:
    unsigned int readIndex;
    unsigned int writeIndex;
    unsigned int bufferSize;
    data_t *buffer;

public:
    Channel();
    Channel(unsigned int s);
    virtual ~Channel();
    // User Interface
    virtual bool readChannel(data_t& data)=0;
    virtual bool writeChannel(data_t& data)=0;
};

#endif