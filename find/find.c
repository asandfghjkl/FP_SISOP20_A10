#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

char *filename(char *path){
	static char buf[DIRSIZ+1];

	char *p;

	for(p = path + strlen(path); p>=path && *p != '/'; p--);
	p++;

	if(strlen(p) >= DIRSIZ)
		return p;
	memmove(buf,p,strlen(p));
	memset(buf+strlen(p),' ',DIRSIZ-strlen(p));
	return buf;
}

int strstr(char *needle, char *haystack){
	int m = strlen(needle);
	int n = strlen(haystack);

	for(int i=0;i<=n-m;i++){
		int j;
		for(j=0;j<m;++j){
			if(haystack[i+j] != needle[j]) break;
		}

		if(j==m)return 1;
	}
	return 0;
}


void ls(char *path, char *needle){
	char buf[512];
	struct dirent de;
	struct stat st;

	int dir = open(path,0);
	if(dir < 0){
		printf(2,"find: cannot access '%s': No such file or directory\n",path);
		return;
	}

	if(fstat(dir,&st) < 0){
		printf(2,"find: cannot stat '%s'\n",path);
		close(dir);
		return;
	}

	if(st.type == T_FILE){
		printf(1,"%s isn't a directory\n", path);
	}
	else if(st.type == T_DIR){
		if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
			printf(1,"find: path too long\n");
			return;
		}
		strcpy(buf,path);
		char *p = buf+strlen(buf);
		*p++ = '/';
		while(read(dir,&de,sizeof (de)) == sizeof (de)){
			if(de.inum == 0) continue;
			memmove(p,de.name, DIRSIZ);
			p[DIRSIZ] = 0;
			if(stat(buf,&st) < 0){
				printf(2,"find: cannot stat '%s'\n",buf);
				continue;
			}

			if(strstr(needle, filename(buf)))
				printf(1,"%s\n",buf);
		}
	}
	close(dir);
	return;
}

int main(int argc, char *argv[])
{
	int flag = 0;
	if(argc < 3) exit();
	for(int i=1; i<argc; i++) {
		if(strcmp(argv[i], "-d") == 0) {
			flag = 1;
			for(int j=1; j<argc; j++) {
				if(strcmp(argv[j], "-n") == 0) ls(argv[i+1], argv[j+1]);
			}
			break;
		}
	}
	if(flag == 0) {
		for(int k=1; k<argc; k++) {
			if(strcmp(argv[k], "-n") == 0) ls(".", argv[k+1]);
		}
	}
	exit();
}
