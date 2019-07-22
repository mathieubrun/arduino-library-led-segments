#ifndef LedSegments_h
#define LedSegments_h

#include <Arduino.h>
#include "LedSegment.h"

class LedSegments
{
    public:
        LedSegments(LedSegment &first, LedSegment &second);
        void writeValue(int segment, int value);
        void writeValue(int value);
        void writeRaw(int segment, byte value);
        void dot(int segment, bool);
        void clear();
        void clear(int segment);

    private:
        LedSegment *_first, *_second;
};

#endif
