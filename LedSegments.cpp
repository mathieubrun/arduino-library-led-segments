#include "LedSegments.h"
#include "LedSegment.h"

LedSegments::LedSegments(LedSegment &first, LedSegment &second)
{
    _first = &first;
    _second = &second;
}

int LedSegments::writeValue(int segment, int value)
{
    if (segment < 0 || segment > 1)
    {
        return -1;
    }

    return segment == 0 ? _first->writeValue(value) : _second->writeValue(value);
}

int LedSegments::writeValue(int value)
{
    if (value < 0 || value > 99)
    {
        return -1;
    }

    return _second->writeValue(value % 10) || _first->writeValue(value / 10);
}

int LedSegments::dot(int segment, bool state)
{
    return segment == 0 ? _first->dot(state) : _second->dot(state);
}

int LedSegments::writeRaw(int segment, byte bits)
{
    if (segment < 0 || segment > 1)
    {
        return -1;
    }

    return segment == 0 ? _first->writeRaw(bits) : _second->writeRaw(bits);
}
