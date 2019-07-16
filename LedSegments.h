#ifndef LedSegments_h
#define LedSegments_h

#include <Arduino.h>
#include "LedSegment.h"

class LedSegments
{
    public:
        LedSegments(LedSegment &first, LedSegment &second);
        int writeValue(int segment, int value);
        int writeValue(int value);
        int writeRaw(int segment, byte value);
        int dot(int segment, bool);

    private:
        LedSegment *_first, *_second;
};

#endif
