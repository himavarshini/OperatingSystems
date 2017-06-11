#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
# define M 20
int main()
{
        int pid,p[2];
	char buf[M];
        if(pipe(p) == -1){
                printf("Error in creating  pipe\n");
                exit(1);
        }
        pid = fork();
        if(pid > 0){
                printf("Enter the string\n");
                scanf("%s",buf);
                close(p[0]);
                write(p[1],buf,M);
                close(p[1]);
        }
        else if(pid ==0){
                close(p[1]);
                int i=0;
                read(p[0],buf,M);
     		while(i<strlen(buf)){
			if((buf[i] >= 'a') && (buf[i] <= 'z')){
				buf[i] = buf[i] - 32;
			}
			i++;
		}
                printf("%s\n",buf);
         }
        return 0;
}
