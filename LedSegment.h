#ifndef LedSegment_h
#define LedSegment_h

#include <Arduino.h>

class LedSegment
{
    public:
        LedSegment(byte pinA, byte pinB, byte pinC, byte pinD, byte pinE, byte pinF, byte pinG, byte pinDot);
        int writeValue(int);
        int writeRaw(byte);
        int dot(bool);

    private:
        byte _pinA, _pinB, _pinC, _pinD, _pinE, _pinF, _pinG, _pinDot;
};

#endif
