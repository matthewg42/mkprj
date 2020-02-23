#include "db.h"

const char* _db_name;
FILE* _db_stream;
db_level_t _db_level;
db_level_info_t _db_level_info[db_5+1];
char _db_buf[DB_MAX_LEN];

void db_set_level(db_level_t level)
{
    _db_level = level;
}

void db_inc_level(db_level_t first)
{
    if (_db_level < first) {
        _db_level = first;
    } else if (_db_level < db_5) {
        _db_level++;
    }
}

void db_init(FILE* stream, const char* name, db_level_t level, int col)
{
    _db_stream = stream;
    _db_name = name;
    db_set_level(level);
    _db_level_info[db_q].id = "QUIET";
    _db_level_info[db_q].col = NULL;
    _db_level_info[db_f].id = "FATAL";
    _db_level_info[db_e].id = "ERROR";
    _db_level_info[db_w].id = "WARN";
    _db_level_info[db_i].id = "INFO";
    _db_level_info[db_1].id = "DEBUG";
    _db_level_info[db_1].col = NULL;
    _db_level_info[db_2].id = "DEBUG-2";
    _db_level_info[db_2].col = NULL;
    _db_level_info[db_3].id = "DEBUG-3";
    _db_level_info[db_3].col = NULL;
    _db_level_info[db_4].id = "DEBUG-4";
    _db_level_info[db_4].col = NULL;
    _db_level_info[db_5].id = "DEBUG-5";
    _db_level_info[db_5].col = NULL;

    int i;
    for (i=0; i<=db_5; i++) {
        _db_level_info[i].col = NULL;
    }
    if (col) {
        _db_level_info[db_f].col = "\033[31m";
        _db_level_info[db_e].col = "\033[31m";
        _db_level_info[db_w].col = "\033[33m";
        _db_level_info[db_i].col = "\033[32m";
        _db_level_info[db_1].col = "\033[36m";
        _db_level_info[db_2].col = "\033[36m";
        _db_level_info[db_3].col = "\033[36m";
        _db_level_info[db_4].col = "\033[36m";
        _db_level_info[db_5].col = "\033[36m";
    }
}

void db(int message_level, const char* fmt, ...)
{
    if (message_level <= _db_level && message_level) {
        // get a timestamp
        char timestamp[DB_TS_LEN];
        time_t t;
        struct tm *tmp;
        t = time(NULL);
        tmp = localtime(&t);
        if (tmp == NULL) {
            strcpy(timestamp, "[ERR-localtime]");
        } else {
            if (strftime(timestamp, sizeof(timestamp), DB_TS_FMT, tmp) == 0) {
                strcpy(timestamp, "[ERR-strftime]");
            }
        }

        // format the message with snprintf into the static _db_buf
        va_list args;
        va_start(args, fmt);
        vsnprintf(_db_buf, DB_MAX_LEN, fmt, args);
        va_end(args);

        fprintf(
            _db_stream,
            "%s %s[%d] %s%s%s: %s",
            timestamp,
            _db_name,
            getpid(),
            _db_level_info[message_level].col ? _db_level_info[message_level].col : "",
            _db_level_info[message_level].id,
            _db_level_info[message_level].col ? "\033[0m" : "",
            _db_buf
        );
    }
}

