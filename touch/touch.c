#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>

int flagging(char *argv[], int k)
{
	struct dirent *de;  
    	DIR *dr = opendir("."); 

	while ((de = readdir(dr)) != NULL) 
        {
		if(strcmp(de->d_name,argv[k])==0)return 1;
	}
	return 0;

}

int main(int argc, char *argv[])
{
	FILE *fileptr;
	FILE *bufferptr;
	char ch;
	int flag;
	
	if(argc==1) printf("Invalid command");
	else
	{
		for(int i=1;i<argc;i++)
		{
			flag = flagging(argv, i);
			if(flag == 1){
				fileptr = fopen(argv[i],"r");
				bufferptr = fopen("buffer.txt", "w");
				while((ch=fgetc(fileptr)) != EOF) fputc(ch,bufferptr);
				fclose(fileptr);
				fclose (bufferptr);
				remove(argv[i]);
	
				fileptr = fopen(argv[i],"w");
				bufferptr = fopen("buffer.txt", "r");
				while( ( ch = fgetc(bufferptr) ) != EOF ) fputc(ch, fileptr);
				fclose(fileptr);
				fclose (bufferptr);
				remove("buffer.txt");
			}
			else{
				fileptr = fopen(argv[i],"w");
				fclose(fileptr);
			}
		}
	}
	return 0;
	
}
