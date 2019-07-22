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

void LedSegment::writeValue(int value)
{
    if (value < 0 || value > 9)
    {
        return;
    }

    byte bits = _numbers[value];

    writeRaw(bits);
}

void LedSegment::dot(bool state)
{
    digitalWrite(_pinDot, state);
}

void LedSegment::writeRaw(byte bits)
{
    digitalWrite(_pinA, (bits & 0b10000000) >> 7);
    digitalWrite(_pinB, (bits & 0b01000000) >> 6);
    digitalWrite(_pinC, (bits & 0b00100000) >> 5);
    digitalWrite(_pinD, (bits & 0b00010000) >> 4);
    digitalWrite(_pinE, (bits & 0b00001000) >> 3);
    digitalWrite(_pinF, (bits & 0b00000100) >> 2);
    digitalWrite(_pinG, (bits & 0b00000010) >> 1);
}

void LedSegment::clear()
{
    digitalWrite(_pinA, 0);
    digitalWrite(_pinB, 0);
    digitalWrite(_pinC, 0);
    digitalWrite(_pinD, 0);
    digitalWrite(_pinE, 0);
    digitalWrite(_pinF, 0);
    digitalWrite(_pinG, 0);
}
