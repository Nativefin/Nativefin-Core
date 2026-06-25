#pragma once
#include <filesystem>
#include <vector>

#include "db.h"
#include "event.h"

namespace NativefinCore {




    class Core {
        std::filesystem::path config_path;
        std::shared_ptr<Database> db;


        std::vector<std::shared_ptr<Event>> events;

    public:
        Core(
    #if defined(__ANDROID__)
    const std::filesystem::path& androidFilesDir
    #endif
        );

        bool poll_events();

        std::vector<std::shared_ptr<Event>> pop_events();
    };
}
