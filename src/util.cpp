#include "util.h"

#include <cstdlib>
#include <filesystem>
#include <string>

#if defined(__APPLE__)
    #include <TargetConditionals.h>
#endif

std::filesystem::path get_config_directory(
#if defined(__ANDROID__)
    const std::filesystem::path& androidFilesDir
#endif
)
{
#if defined(_WIN32)

    if (const char* appData = std::getenv("APPDATA"))
        return std::filesystem::path(appData) / "Nativefin";

    if (const char* userProfile = std::getenv("USERPROFILE"))
        return std::filesystem::path(userProfile) /
               "AppData" / "Roaming" / "Nativefin";

    return "Nativefin";

#elif defined(__APPLE__) && TARGET_OS_IPHONE

    if (const char* home = std::getenv("HOME"))
    {
        return std::filesystem::path(home) /
               "Library" /
               "Application Support" /
               "Nativefin";
    }

    return "Nativefin";

#elif defined(__APPLE__)

    if (const char* home = std::getenv("HOME"))
    {
        return std::filesystem::path(home) /
               "Library" /
               "Application Support" /
               "Nativefin";
    }

    return "Nativefin";

#elif defined(__ANDROID__)

    // Should be something like:
    // /data/user/0/com.example.app/files
    return androidFilesDir / "Nativefin";

#elif defined(__linux__) || defined(__EMSCRIPTEN__)

    if (const char* xdg = std::getenv("XDG_CONFIG_HOME"))
    {
        if (*xdg)
            return std::filesystem::path(xdg) / "Nativefin";
    }

    if (const char* home = std::getenv("HOME"))
        return std::filesystem::path(home) / ".config" / "Nativefin";

    return "Nativefin";

#else

    return "Nativefin";

#endif
}