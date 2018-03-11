#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

void main() 
{         
	int shmid;         
	int  *b;         
	int i,n;
	key_t key= 1234;
	shmid = shmget(key, 2*sizeof(int), 0777|IPC_CREAT); 
	
	  printf("%d",shmid); 
		b = (int *) shmat(shmid, NULL, 0);
		printf("\t\t enter five numbers :"); 
		for( i=0; i<5 ; i++) 
		{        
			scanf("%d",&n);                 	
			*(b+i) = n;
			
		} 
		for( i=0; i<5 ; i++) 
		{        
			printf("%d",b[i]);
			
		} 
		
		
		shmdt(b); 
		//shmctl(shmid, IPC_RMID, 0); 
	}      
	   