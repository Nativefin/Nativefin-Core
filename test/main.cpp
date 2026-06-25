#include <iostream>
#include "../src/core.h"

int main(int argc, char** argv) {
    NativefinCore core;


    while (true) {
        core.poll_events();
    }


    return 0;
}
