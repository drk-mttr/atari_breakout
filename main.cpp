#define OLC_PGE_APPLICATION
#include "breakout.h"

int main() {
    BreakOut demo;
    if (demo.Construct(192, 240, 2, 2, false, true))
        demo.Start();
    return 0;
}