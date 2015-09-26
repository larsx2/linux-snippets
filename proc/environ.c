#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>

 extern char ** environ;
                                
int main(int argc, char ** argv/*, char ** environ */) {
    char **ep;

    for (ep = environ; *ep != NULL; ep++) {
        puts(*ep);
    }

    // inspecting an env var
    char *current_shell = getenv("SHELL");
    if (current_shell != NULL)
        printf("The current SHELL is %s\n", current_shell);

    // setting an env var
    setenv("foo", "bar", 1);
    assert(strcmp(getenv("foo"), "bar") == 0);

    exit(EXIT_SUCCESS);
}
