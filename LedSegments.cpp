#include "LedSegments.h"
#include "LedSegment.h"

LedSegments::LedSegments(LedSegment &first, LedSegment &second)
{
    _first = &first;
    _second = &second;
}

void LedSegments::writeValue(int segment, int value)
{
    if (segment < 0 || segment > 1)
    {
        return;
    }

    segment == 0 ? _first->writeValue(value) : _second->writeValue(value);
}

void LedSegments::writeValue(int value)
{
    if (value < 0 || value > 99)
    {
        return;
    }

    _first->writeValue(value / 10);
    _second->writeValue(value % 10);
}

void LedSegments::dot(int segment, bool state)
{
    segment == 0 ? _first->dot(state) : _second->dot(state);
}

void LedSegments::writeRaw(int segment, byte bits)
{
    if (segment < 0 || segment > 1)
    {
        return;
    }

    segment == 0 ? _first->writeRaw(bits) : _second->writeRaw(bits);
}

void LedSegments::clear(int segment)
{
    segment == 0 ? _first->clear() : _second->clear();
}

void LedSegments::clear()
{
    _first->clear();
    _second->clear();
}
