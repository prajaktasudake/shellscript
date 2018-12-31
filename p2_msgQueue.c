#include<unistd.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 0x1219

int main(int argc, char *argv[])
{	
	char str[40];
	int ret;
	int mid,k;
	char buf[100];
	mid=msgget(KEY,IPC_CREAT|0666);
	//IPC_CREAT ==> create if not exists,or
	//give mid if already exists with given key
	if(mid<0) {
		perror("msgget");
		exit(0);
	}	
	ret=fork();
	if(ret<0){
		printf("fork failed\n");
	}
	if(ret>0){
		printf("in parent\n");
		if(argc>1){
			strcpy(str, argv[1]);
		}else {
			strcpy(str, "Def Msg");
		}

		k=msgsnd(mid,str,strlen(str)+1,0);
		// mid - id of msg queue
		// str - message to pass
		// size of message 
		// message flag 
		if(k<0) {
			perror("msgsnd");
			exit(0);
		}
		printf("successfully sent\n");
	}
	if(ret==0){
		printf("in child\n");
		msgrcv(mid,buf,70,0,0);
		// mid - id of msg queue
		// pointer to buffer
		// size of msg
		// type of msg 
		// message flag

		printf("in child recived msg=%s\n",buf);
	}
	return 0;
}


