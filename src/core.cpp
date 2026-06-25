#include "core.h"
#include "util.h"
#include "db.h"

namespace NativefinCore {
    NativefinCore::NativefinCore(
    #if defined(__ANDROID__)
        const std::filesystem::path& androidFilesDir
    #endif
    ) {
        this->config_path = get_config_directory(
    #if defined(__ANDROID__)
            androidFilesDir
    #endif
        );


        init_db(config_path);
    }

    void NativefinCore::poll_events() {

    }
}
