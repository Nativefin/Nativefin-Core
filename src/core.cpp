#include "core.h"

#include <iostream>

#include "util.h"
#include "db.h"

namespace NativefinCore {
    Core::Core(
    #if defined(__ANDROID__)
        const std::filesystem::path& androidFilesDir
    #endif
    ) {
        this->config_path = get_config_directory(
    #if defined(__ANDROID__)
            androidFilesDir
    #endif
        );

        if (!std::filesystem::exists(config_path)) {
            std::filesystem::create_directory(config_path);
        }

        this->db = std::make_shared<Database>(config_path);
    }

    bool Core::poll_events() {
        return true;
    }

    std::vector<std::shared_ptr<Event>> Core::pop_events() {
        return {};
    }
}
