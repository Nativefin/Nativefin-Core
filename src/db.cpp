#include "db.h"
#include <filesystem>

namespace NativefinCore {
    std::pair<int, std::string> Database::db_exec(const std::string& sql, int (*callback)(void *, int, char **, char **), void *data) const {
        char* errMsg;

        int rc = sqlite3_exec(db, sql.c_str(), callback, data, &errMsg);

        return std::make_pair(rc, errMsg != nullptr ? std::string(errMsg) : std::string());
    }

    Database::Database(std::filesystem::path const& config_path) {
        if (sqlite3_open((config_path / "storage.db").string().c_str(), &db) != SQLITE_OK)
            throw std::runtime_error(std::string("Unable to open database! Error: ") + sqlite3_errmsg(db));

        std::string create_servers_table_command = R"(
            CREATE TABLE IF NOT EXISTS SERVERS (
                uuid TEXT PRIMARY KEY,
                name TEXT NOT NULL,
                address TEXT NOT NULL,
                version TEXT NOT NULL
            );
        )";

        if (std::pair<int, std::string> res = db_exec(create_servers_table_command, nullptr, nullptr); res.first != SQLITE_OK)
            throw std::runtime_error(std::string("Unable to execute command! Error: ") + res.second);

    }

    Database::~Database() {
        sqlite3_close(db);
    }
}
