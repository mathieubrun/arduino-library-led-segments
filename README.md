# LedSegments

## Usage

### Initialization

```` c
#include <LedSegments.h>

LedSegment segment0LED1_A, LED1_B, LED1_C, LED1_D, LED1_E, LED1_F, LED1_G, LED1_DOT);
LedSegment segment1(LED2_A, LED2_B, LED2_C, LED2_D, LED2_E, LED2_F, LED2_G, LED2_DOT);

LedSegments segments(segment0, segment1);
````

### Turn dot on/off

```` c
segment0.dot(true);
segments.dot(1, false);
````

### Write value

```` c
segment0.writeValue(4);
segments.writeValue(42);
````