#include <stdio.h>
#include <stdlib.h>

char globBuf[65535];             // Unitialized data segment (BSS)
int primes[] = { 2, 3, 65, 7 };  // Initialized data segment

static int
square(int x) {      // Allocated to frame square()
    int result;      // Allocated to frame square()

    result = x * x;  
    return result;   // Return value passed via register
}

static void 
doCalc(int val) {     // Allocated to frame doCalc()
    printf("the square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;        // Allocated to frame doCalc()

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int 
main(int argc, char ** argv) {
    static int key = 9973;       // Allocated in frame for main()
    static char mbuf[10240000];  // Initialized data segment

    char *p;                     // Allocated for frame main()

    p = malloc(1024);            // Points to memory in heap segment

    doCalc(key);

    exit(EXIT_SUCCESS);
}
