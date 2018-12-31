#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	printf("before fork\n");
	int ret, status;
	ret=fork(); 
	if(ret<0){
		printf("fork failed\n");
		exit(1);
	}
	if(ret==0){
		printf("in parent pid=%d ppid=%d\n ",getpid(), getppid());
		//exit(111);
		while(1);
	}
	if(ret > 0 ) {
		printf("in parent pid=%d ppid=%d\n ",getpid(), getppid());
		wait(&status);
	if (WIFEXITED(status)) {
            printf("exited, status=%d\n", WEXITSTATUS(status));
         } else if (WIFSIGNALED(status)) {
                       printf("killed by signal %d\n", WTERMSIG(status));}
	 else {
		printf("some other reason \n");
	}
	 
	
	printf("after fork\n");
	
	}
}





