#include <stdio.h>
#include <stdlib.h>

void read_stdin(void);
void print_file(char *file_path);

int main(int argc, char **argv) {
	if (argc < 2) {
		read_stdin();
	}

	for (int i = 1; i < argc; i++) {
		print_file(argv[i]);
	}
}

void read_stdin(void) {
	int buffer_length = 256;
	char buffer[buffer_length];

	while (fgets(buffer, buffer_length, stdin)) {
		printf("%s", buffer);
	}
}

void print_file(char *file_path) {
	FILE *file = fopen(file_path, "r");

	if (!file) {
		printf("kitten: %s: No such file or directory\n", file_path);
		exit(EXIT_FAILURE);
	}

	int buffer_length = 255;
	char buffer[buffer_length];

	while (fgets(buffer, buffer_length, file)) {
		printf("%s", buffer);
	}

	fclose(file);
}
