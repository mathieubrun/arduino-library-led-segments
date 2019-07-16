#include "LedSegment.h"

byte _numbers[] = {
    0b11111100, // 0
    0b01100000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100000, // 7
    0b11111110, // 8
    0b11110110  // 9
};

LedSegment::LedSegment(byte pinA, byte pinB, byte pinC, byte pinD, byte pinE, byte pinF, byte pinG, byte pinDot)
{
    _pinA = pinA;
    _pinB = pinB;
    _pinC = pinC;
    _pinD = pinD;
    _pinE = pinE;
    _pinF = pinF;
    _pinG = pinG;
    _pinDot = pinDot;

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinDot, OUTPUT);
}

int LedSegment::writeValue(int value)
{
    if (value < 0 || value > 9)
    {
        return -1;
    }

    byte bits = _numbers[value];

    return writeRaw(bits);
}

int LedSegment::dot(bool state)
{
    digitalWrite(_pinDot, state);
}

int LedSegment::writeRaw(byte bits)
{
    digitalWrite(_pinA, (bits & 0b10000000) >> 7);
    digitalWrite(_pinB, (bits & 0b01000000) >> 6);
    digitalWrite(_pinC, (bits & 0b00100000) >> 5);
    digitalWrite(_pinD, (bits & 0b00010000) >> 4);
    digitalWrite(_pinE, (bits & 0b00001000) >> 3);
    digitalWrite(_pinF, (bits & 0b00000100) >> 2);
    digitalWrite(_pinG, (bits & 0b00000010) >> 1);

    return 0;
}
