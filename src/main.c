#include <stdio.h>
#include <string.h>

FILE *HISTFILE = NULL;
int LIST_COUNT = 10;

int main(int argc, char** argv) {
	for(int i = 1; i < argc; i++) {
		char *arg = argv[i];
		if(!strncmp(arg, "-f", 2)) {
			if (argc - 1 < i) {
				HISTFILE = fopen(arg + 1, "r");
				if (HISTFILE == NULL) {
					fprintf(stderr, "Error: invalid file '%s'!", arg + 1);
				}
			}
		} else if (!strncmp(arg, "-c", 2)) {
			if (argc - 1 < i) {
				
			}
		}
	}
	if (HISTFILE == NULL) {
		fprintf(stderr, "Error: no histfile given!");
	}
}
