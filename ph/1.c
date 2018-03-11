#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
int pid, pid1;
printf("%d\n",(int)getpid());
pid = fork();
if(pid==0){
 printf("%d, %d\n",(int)getpid(),(int)getppid());
 pid1= fork();
if(pid1==0)
 printf("%d, %d\n",(int)getpid(),(int)getppid());
}
}

