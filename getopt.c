#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void Usage(char *arg)
{
	fprintf(stderr, "Usage: %s -n\n", arg);
	fprintf(stderr, "       %s -t parameter\n", arg);
}

int main(int argc, char **argv)
{
	int opt;

	while ( (opt = getopt(argc, argv, "nt:")) != -1) {
		switch (opt) {
		case 'n':
			fprintf(stdout, "cmd is -n\n");
			break;
		case 't':
			fprintf(stdout, "cmd is -t\n");
			fprintf(stdout, "parameter is %s\n", optarg);
			break;
		case '?':
			fprintf(stdout, "Invalid '%c'\n", optopt);
			Usage(argv[0]);
			break;
		default:
			Usage(argv[0]);
			break;
		}	
	}

	if (argc == 1) {
		fprintf(stderr, "no parameter\n");
		Usage(argv[0]);
	}

	fprintf(stdout, "optind = %d, argc = %d\n", optind, argc);
	
	return 0;
}
