#ifndef AXIS_H
#define AXIS_H

#include <Arduino.h>

class Axis
{
private:
    int plusPin;
    int minusPin;
public:
    Axis(int plusPin, int minusPin);
    ~Axis();
    void reset();
    void setup();
    void plus();
    void minus();
};
#endif //AXIS_H
