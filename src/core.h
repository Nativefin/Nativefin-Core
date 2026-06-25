#pragma once
#include <filesystem>

namespace NativefinCore {
    class NativefinCore {
        std::filesystem::path config_path;

    public:
        NativefinCore(
    #if defined(__ANDROID__)
    const std::filesystem::path& androidFilesDir
    #endif
        );

        void poll_events();
    };
}