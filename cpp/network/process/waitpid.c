/*************************************************************************
	> File Name: wait.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月19日 星期日 16时02分40秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv)
{
	int status;
	pid_t pid = fork();
	if(pid == 0){
		sleep(15);
		return 24;
	}
	else {
		while(!waitpid(-1,&status,WNOHANG))
		{
			sleep(3);
			puts("sleep 3sec");
		}
		if(WIFEXITED(status))
				printf("child send one: %d \n",WEXITSTATUS(status));
		}
	return 0;
}
