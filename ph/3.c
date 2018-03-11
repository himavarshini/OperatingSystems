#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	int pid, pid1,pid2, pid3, pid4;

	printf("%d\n\n",(int)getpid());
	pid = fork();

	if(pid==0){
	 printf("%d, %d\n",(int)getpid(),(int)getppid());
	 printf("\n");
	}

	if(pid==0){
	 pid1= fork();
	 if(pid1>0){
		 //printf("%d\n",(int)getpid());
		 printf("\n");
		 pid2 = fork();
		 if(pid2==0 || pid1==0)
		  printf("%d, %d\n",(int)getpid(),(int)getppid());
	 }
	}

	if(pid>0){
		pid3 = fork();
		if(pid3==0)
		  printf("%d, %d\n",(int)getpid(),(int)getppid());
		if(pid3>0){
			pid4 = fork();
			if(pid4==0)
		  		printf("%d, %d\n",(int)getpid(),(int)getppid());
		}
	}
}

