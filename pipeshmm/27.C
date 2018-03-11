#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define MSGSIZE 16

int main()
{
	int inbuf1,inbuf2;
	int hell1,hell2;
	int res1,res2;
	int p1[2];
	int p2[2];
	int p3[2];
	int p4[2];
	int n1,n2;
	pid_t pid; 
		
	/*open pipe*/
	if(pipe(p1)==-1)
	{
		perror("pipe call");
		exit(1);
	}
	if(pipe(p2)==-1)
	{
		perror("pipe call");
		exit(1);
	}
	if(pipe(p3)==-1)
	{
		perror("pipe call");
		exit(1);
	}
	if(pipe(p4)==-1)
	{
		perror("pipe call");
		exit(1);
	}


	switch(pid = fork())
	{
		case -1:
			perror("Fork Failure");
			exit(2);
		case 0:
			/*if child,then read from pipe and check armstrong number*/
			close(p1[1]);
			while(read(p1[0],&inbuf1,MSGSIZE))
			{
				int temp = inbuf1;
				int k;
				int sum=0;
				while(temp>0)
				{
					k = temp%10;
					temp = temp/10;
					sum = sum + (k*k*k);
				}
				if(sum==inbuf1)
					hell1=1;
				else
					hell1=2;		
					
				
			}
			close(p1[0]);
			close(p2[0]);
			write(p2[1],&hell1,MSGSIZE);
			close(p2[1]);

			break;
		default:
			/*if parent,then write into pipe */
			
			switch(pid = fork())
			{
				case -1:
					perror("Fork Failure");
					exit(2);
				case 0:
					//if child,then read from pipe and check armstrong number
					sleep(2);
					close(p3[1]);
					while(read(p3[0],&inbuf2,MSGSIZE))
					{
						int i=1,sum=0;
						while(i < inbuf2)
						{
							if(inbuf2%i == 0)
								sum=sum+i;
							i++;
						}
						if(sum == inbuf2)
							hell2=1;
						else
							hell2=2;
					}
					close(p3[0]);
					close(p4[0]);
					write(p4[1],&hell2,MSGSIZE);
					close(p4[1]);
					break;
				default:
					printf("enter any two numbers:\n");
					scanf("%d",&n1);
					scanf("%d",&n2);
					close(p1[0]);
					write(p1[1],&n1,MSGSIZE);
					close(p1[1]);

					close(p3[0]);
					write(p3[1],&n2,MSGSIZE);
					close(p3[1]);

					sleep(2);

					close(p2[1]);
					while(read(p2[0],&res1,MSGSIZE))
					{
						if(res1==1)
							printf("Armstrong\n");
						else
							printf("Not Armstrong\n");
					}
					close(p2[0]); 
					
					close(p4[1]);
					while(read(p4[0],&res2,MSGSIZE))
					{
						if(res2==1)
							printf("Perfect\n");
						else
							printf("Not Perfect\n");
					}
					close(p4[0]);
			}
			
										
			//wait(NULL);
	}
	
	exit(0);
}
