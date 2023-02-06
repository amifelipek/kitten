#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void help(void);
void version(void);

void print_stdin(void);
void print_file(char *file_path);

int main(int argc, char **argv)
{
	int help_flag = 0;
	int version_flag = 0;

	int c;

	while ((c = getopt(argc, argv, "hv")) != -1) {
		switch (c) {
		case 'h':
			help_flag = 1;
			break;
		case 'v':
			version_flag = 1;
			break;
		default:
			help_flag = 1;
			break;
		}
	}

	if (help_flag) {
		help();
	}

	if (version_flag) {
		version();
	}

	if (argc < 2) {
		print_stdin();
	}

	for (int i = 1; i < argc; i++) {
		print_file(argv[i]);
	}
}

void print_stdin(void)
{
	int buffer_length = 256;
	char buffer[buffer_length];

	while (fgets(buffer, buffer_length, stdin)) {
		printf("%s", buffer);
	}
}

void print_file(char *file_path)
{
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

void help(void)
{
	printf("Usage: kit [OPTION]\n");
	printf("Outputs files to stardard output.\n");
	printf("\n  -v\t\t\toutput version information and exit.\n");
	printf("  -h\t\t\tdisplay this help and exit.\n");
	exit(EXIT_SUCCESS);
}

void version(void)
{
	printf("kit 0.1\n");
	printf("\nWritten by Felipe Kinoshita.\n");
	exit(EXIT_SUCCESS);
}
