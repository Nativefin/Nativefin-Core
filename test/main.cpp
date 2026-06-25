#include <iostream>
#include <thread>

#include "../src/core.h"

int main(int argc, char** argv) {
    NativefinCore::Core core;


    while (core.poll_events()) {
        std::vector<void*> events = core.pop_events();

        for (auto event : events) {

        }

        // sleep to give the thread back to the os
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }


    return 0;
}
