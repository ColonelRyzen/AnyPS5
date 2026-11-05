#include "prx/libSceNKWebKitRequirements/include/Identified.hpp"
#include <cstdio>

namespace {

int failures = 0;

template <typename TFn>
void RequireThrows(TFn fn, const char *name) {
    try {
        fn();
    } catch (...) {
        return;
    }
    std::fprintf(stderr, "%s did not throw\n", name);
    ++failures;
}

}

int main() {
    RequireThrows(sqlite3_bind_text_nid_postfix, "sqlite3_bind_text");
    RequireThrows(sqlite3_changes_nid_postfix, "sqlite3_changes");
    RequireThrows(sqlite3_column_name_nid_postfix, "sqlite3_column_name");
    RequireThrows(sqlite3_column_text_nid_postfix, "sqlite3_column_text");
    RequireThrows(sqlite3_config_nid_postfix, "sqlite3_config");
    RequireThrows(sqlite3_db_release_memory_nid_postfix, "sqlite3_db_release_memory");
    RequireThrows(sqlite3_stmt_readonly_nid_postfix, "sqlite3_stmt_readonly");
    RequireThrows(sqlite3_value_bytes_nid_postfix, "sqlite3_value_bytes");
    RequireThrows(sqlite3_value_text_nid_postfix, "sqlite3_value_text");
    return failures == 0 ? 0 : 1;
}
