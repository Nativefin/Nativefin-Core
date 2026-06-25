#pragma once

#include <filesystem>
#include <sqlite3.h>

namespace NativefinCore {
    class Database {
        sqlite3* db = nullptr;
        sqlite3_stmt* stmt = nullptr;

        std::pair<int, std::string> db_exec(const std::string& sql, int(*callback)(void *, int, char **, char **), void *data) const;
    public:
        Database(std::filesystem::path const& config_path);

        ~Database();
    };
}