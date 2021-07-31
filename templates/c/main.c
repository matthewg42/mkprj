// (C) __YEAR__ __AUTHOR__
//
// __SHORT_DESC__
//

#include <stdio.h>
#include <simdb.h>

int main(int argc, char** argv)
{
    db_init(stderr, argv[0], db_i, 0);
    db(db_i, "The program was invoked with %d command line arguments,\n", argc-1);
    return 0;
}

