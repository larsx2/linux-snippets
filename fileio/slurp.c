#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Expected %s [filepath]\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fh = fopen(argv[1], "rb");

    if (fh == NULL) {
        printf("Failed to read file\n");
        return EXIT_FAILURE;
    }

    fseek(fh, 0, SEEK_END);

    long filesize = ftell(fh);

    rewind(fh);

    char *buffer = malloc(filesize);
    if (buffer == NULL) {
        printf("Failed to allocate memory\n");
        return EXIT_FAILURE;
    }

    fread(buffer, filesize, 1, fh);
    fclose(fh);

    fwrite(buffer, filesize, 1, stdout);
    free(buffer);

    return EXIT_SUCCESS;
}
