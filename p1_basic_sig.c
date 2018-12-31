#include<stdio.h>
#include<signal.h>

int main(){
	sigset_t set1, set2;

	sigfillset(&set1);
	sigdelset(&set1, SIGINT);
	
	sigprocmask(SIG_SETMASK, &set1, &set2);

	sigsuspend(&set1);
	
	

}
