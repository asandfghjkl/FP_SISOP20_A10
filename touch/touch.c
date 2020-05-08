#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
	int file;
	char cpfile[1000];
	if(argc < 2) {
		printf(1, "can't exec touch.\npls enter minimimum 2 arguments:\ntouch <filename>\n");
	}
	for(int i=0; i<=argc; i++) {
		memset(cpfile, '\0', sizeof(cpfile));
		file = open(argv[i], O_CREATE | O_RDWR);
		if(file < 0) {
			printf(2, "can't exec touch: %s failed to create\n", argv[i]);
		}
		else {
			while(read(file, cpfile, sizeof(cpfile)) > 0) {}
			if(strlen(cpfile)>0) write(file, "", 1);
		}
		close(file);
	}
	exit();
}
