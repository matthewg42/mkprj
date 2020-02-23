#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include "db.h"

#define PROG_NAME       "__PROGNAME__"
#define PROG_AUTHOR     "__AUTHOR__"
#define PROG_VERSION    "1.0.0"
#define PROG_YEAR       __YEAR__

void print_usage(int exit_status)
{
    fprintf(exit_status == EXIT_SUCCESS ? stdout : stderr,
            "Usage:\n\n%s [options]\n\n"
            "Options:\n"
            "-Q -F -E -W -I -D set diagnostic output (quiet, fatal, error, warn, info, debug\n"
            "-h      : this cruft\n"
            "-V      : print version and exit\n\n",
            _db_name);
    exit(exit_status);
}

void print_version()
{
    printf("%s version %s\n(C) %d %s\n", PROG_NAME, PROG_VERSION, PROG_YEAR, PROG_AUTHOR);
    exit(EXIT_SUCCESS);
}

int main(int argc, char** argv)
{
    db_init(stderr, basename(argv[0]), db_i, 1);
    db(db_3, "%s: about to process command line args\n", __func__);
    int flags, opt;
    while ((opt = getopt(argc, argv, "QFEWIDVh")) != -1) {
        switch (opt) {
        case 'Q':
            db_set_level(db_q);
            break;
        case 'E':
            db_set_level(db_e);
            break;
        case 'W':
            db_set_level(db_w);
            break;
        case 'I':
            db_set_level(db_i);
            break;
        case 'D':
            db_inc_level(db_1);
            break;
        case 'h':
            print_usage(EXIT_SUCCESS);
            break;
        case 'V':
            print_version();
            break;
        default:
            print_usage(EXIT_FAILURE);
        }
    }
    db(db_i, "%s: first param idx=%d '%s'\n", __func__, optind, argv[optind]);
    return EXIT_SUCCESS;
}

