#include<stdio.h>


int main(){
//	printf("before fork\n");
	int ret, i;
	for(i=0;i<2;i++)
	{ 
	ret=fork(); 
	if(ret<0){
		printf("fork failed\n");
		exit(1);
	}
	if(ret==0){
		printf("child pid=%d ppid=%d\n ", getpid(), getppid());
		break;
	}
	if(ret > 0 ) {
		printf("parent pid=%d ppid=%d \n ", getpid(), getppid());
	} 
	}
//	printf("after fork\n");
	
	while(1);
}





