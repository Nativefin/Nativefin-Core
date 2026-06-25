#pragma once
#include <memory>

enum EventType {
    SCREEN_CHANGE,
    SCREEN_DATA
};

struct Event {
    EventType type;
    std::shared_ptr<void> data;
};
