#ifndef LedSegment_h
#define LedSegment_h

#include <Arduino.h>

class LedSegment
{
    public:
        LedSegment(byte pinA, byte pinB, byte pinC, byte pinD, byte pinE, byte pinF, byte pinG, byte pinDot);
        void writeValue(int);
        void writeRaw(byte);
        void dot(bool);
        void clear();

    private:
        byte _pinA, _pinB, _pinC, _pinD, _pinE, _pinF, _pinG, _pinDot;
};

#endif
