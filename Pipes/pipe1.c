#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
# define M 4
int main()
{
	int n,pid;
	int p[2];
	if(pipe(p) == -1){
		printf("Error in creating  pipe\n");
		exit(1);
	}
	pid = fork();
	if(pid > 0){
		printf("Enter a number\n");
		scanf("%d",&n);	
		close(p[0]);
		write(p[1],&n,M);
		close(p[1]);
	}
	else if(pid ==0){
		close(p[1]);
		int i=1;
		while(read(p[0],&n,M)){
		while(i<=n){
			if((i%2) != 0)
				printf("%d\t",i);
			i++;
		}
		}
		printf("\n");
	 }
	return 0;
}
	
		
