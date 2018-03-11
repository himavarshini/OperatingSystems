#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
void main() 
{         
	int shmid,status;         
	char *a,*b;         
	int i;
	shmid = shmget(IPC_PRIVATE, 10*sizeof(char), 0777|IPC_CREAT); 
	if (fork() == 0) 
	{ 
		sleep(2);
		b = (char *) shmat(shmid, 0, 0);
		for(i=0;i<10;i++)
		{
			*(b+i)=*(b+i)-32;  
		}
		printf("%s",b);
		shmdt(b); 
	}         
	else 
	{ 
		a = (char*) shmat(shmid, 0, 0);
		printf("Enter a string: \n");
		scanf("%s",a);                           
		wait(&status); 
		shmdt(a); 
		shmctl(shmid, IPC_RMID, 0); 
	} 
} 