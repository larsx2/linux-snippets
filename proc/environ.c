#include <stdio.h>
#include <stdlib.h>

// environ can be accessed this way as well
// extern char ** environ;

int main(int argc, char ** argv, char ** environ) {
    char **ep;

    for (ep = environ; *ep != NULL; ep++) {
        puts(*ep);
    }

    exit(EXIT_SUCCESS);
}
