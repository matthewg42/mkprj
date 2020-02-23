#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

#define DB_MAX_LEN 512
#define DB_TS_FMT "%Y-%m-%d %T%z"
#define DB_TS_LEN 26

typedef enum {
    db_q=0,
    db_f,
    db_e,
    db_w,
    db_i,
    db_1,
    db_2,
    db_3,
    db_4,
    db_5
} db_level_t;

typedef struct {
    const char* id;
    const char* col;
} db_level_info_t;

extern FILE* _db_stream;
extern const char* _db_name;
extern db_level_t _db_level;

// Initialize the debugging library
//
// \param stream is a FILE where to send debugging messages, e.g. stderr
// \param name is the name of the program (usually argv[0])
// \param level is the initial debugging level, typically db_i
// \param col should be 0 to suppress color output, else 1
void db_init(FILE* stream, const char* name, db_level_t level, int col);

// Set the debugging level from now on
void db_set_level(db_level_t level);

// Increase the debugging level by one, starting at first
void db_inc_level(db_level_t first);

// Print a debugging message if message_level <= current debugging level
void db(int message_level, const char* fmt, ...);

