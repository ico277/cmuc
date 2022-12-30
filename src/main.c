#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *HISTFILE = NULL;
int DISPLAY_COUNT = 10;

int main(int argc, char** argv) {
    for(int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if(!strncmp(arg, "-f", 2)) {
            if (i < argc - 1) {
                HISTFILE = fopen(argv[i + 1], "r");
                if (HISTFILE == NULL) {
                    fprintf(stderr, "Error: invalid file '%s'!\n", argv[i + 1]);
                }
            }
        }
        else if (!strncmp(arg, "-c", 2)) {
            if (i < argc - 1 ) {
                long num = strtol(argv[i + 1], NULL, 10);
                //if (num > )
            }
        }
    }
    if (HISTFILE == NULL) {
        fprintf(stderr, "Error: no histfile given!\n");
    }
}
