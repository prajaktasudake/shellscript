#include<stdio.h>

int var1=10;

int main(){
	printf("before fork\n");
	
	fork(); 
	
	var1=var1+1;
	
	printf("hello world var1=%d\n",var1);
	while(1);
}
