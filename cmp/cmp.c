#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char file1[1000], file2[1000];

void cmp() {
	int line = 1;

	for (int i=0; i<sizeof(file1) && i<sizeof(file2); i++) {
		if (file1[i]=='\n') line++;
		if (file1[i] > file2[i] || file1[i] < file2[i]) {
			printf(1,"byte %d, line %d\n", i+1, line);
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	int f1, f2;
	if (argc != 3) {
		printf(1,"can't exec cmp\npls enter the correct format: cmp <file1> <file2>\n");
		exit();
	}
	if ((f1 = open(argv[1], O_RDONLY)) < 0){
		printf(1, "can't exec cmp: can't open %s\n", argv[1]);
		exit();
	}

	if ((f2 = open (argv[2], O_RDONLY)) < 0){
		printf(1, "can't exec cmp: can't open %s\n", argv[2]);
		exit();
	}

	while (read(f1, file1, sizeof(file1)) > 0 ) {}
	while (read(f2, file2, sizeof(file2)) > 0 ) {}

	cmp();

	close(f1);
	close(f2);
	exit();

	return 0;
}
