#ifndef  CHANNEL_H
#define CHANNEL_H

class Channel
{
    private:
    unsigned int readIndex;
    unsigned int writeIndex;
    unsigned int bufferSize;
    int* buffer;
    public:
    Channel();
    Channel(unsigned int s);
    ~Channel();
    //User Interface
    bool readChannel(int& data);
    bool writeChannel(int& data);
};

#endif