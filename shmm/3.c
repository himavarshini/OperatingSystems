#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

void main() 
{         
	int shmid,status;         
	int *a,*b;         
	int i;
	shmid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT); 
	if (fork() == 0) 
	{ sleep(2);
		b = (int *) shmat(shmid, 0, 0);
		printf("\t\tOdd numbers till n:"); 
		for( i=0; i<=b[0]; i++) 
		{                         	
			if (i%2!=0)
			{
				printf("\t\t%d\n",i);
			}
		} 
		shmdt(b); 
	}         
	else 
	{ 
		a = (int *) shmat(shmid, 0, 0);
		printf("Enter a number n: \n");
		scanf("%d",a);                           
		wait(&status); 
		shmdt(a); 
		shmctl(shmid, IPC_RMID, 0); 
	} 
} 