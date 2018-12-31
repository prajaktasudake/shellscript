#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>


#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/sem.h>

const int max=10;
#define KEY1 1519

struct shmarea {

  int count;

};

struct shmarea *shma;
int main()
{
	int ret,i=0, id, status;

	id =  shmget(KEY1,4096,IPC_CREAT|0600);
 	shma = shmat(id,0,0);
	printf("shared mem\n");

   	shma->count = 0;

	ret=fork();
	if(ret==0)
	{
		printf("I am in child process context\n");
           	printf("in child .. ppid is %lu ...and pid is %lu\n",
                   getppid(),getpid());
		
		while(i++ < 3) { 
			printf("in child process %d-------->>>\n",++shma->count); 
			//sleep(1);
		}
	}
	else
	{	
		printf("I am in parent process context\n");
           	printf("in parent .. ppid is %lu ...and pid is %lu\n",
                   getppid(),getpid());

		while(i++ < 3) {
		
		printf("in parent process %d---------->>>\n", --shma->count);
	       	//sleep(1);	
		}
		
		wait(&status);
	}


	return 0;

}


	



