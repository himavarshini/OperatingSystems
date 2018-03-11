#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

#define SHMSZ     27
main()
{
    int shmid;
    key_t key;
    char *shm, s[6];
    strcpy(s,"memory");	
    printf("%s",s);    
/*
     * We need to get the segment named
     * "5678", created by the server.
     */
    key = 5678;

    /*
     * Locate the segment.
     */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /*
     * Now read what the server put in the memory.
     */
 *shm='3';
	int i;
/*	for(i=0;i<6;i++)
	{
		*(shm+i)=s[i]
	}*/
 strcpy(shm+1,s);


}
