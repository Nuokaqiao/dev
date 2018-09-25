/*************************************************************************
	> File Name: zombie.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月19日 星期日 15时55分04秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	pid_t pid = fork();
	if(pid == 0)
		puts("i am a child process");
	else {		
		printf("child process ID: %d \n",pid);
		sleep(30);
	}
	if(pid == 0)
		puts("End child process");
	else 
		puts("End parent process");
	return 0;
}
