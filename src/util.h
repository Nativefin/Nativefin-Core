#pragma once
#include <filesystem>

std::filesystem::path get_config_directory(
#if defined(__ANDROID__)
    const std::filesystem::path& androidFilesDir
#endif
);