/*************************************************************************
	> File Name: remove_zombie.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月19日 星期日 18时36分08秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

void read_childproc(int sig)
{
	int status;
	pid_t id = waitpid(-1,&status,WNOHANG);
	if(WIFEXITED(status)){
		printf("Removed proc id : %d \n",id);
		printf("child send: %d \n",WEXITSTATUS(status));
	}
}

int main(int argc,char **argv)
{
	pid_t pid;
	struct sigaction act;
	act.sa_handler = read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGCHLD,&act,0);

	pid = fork();
	if(pid == 0){
		puts("Hi I am child process");
		sleep(10);
		return 12;
	} else {
		printf("Child proc id: %d \n",pid);
		pid = fork();
		if(pid == 0){
			puts("Hi im child pricess");
			sleep(10);
			exit(24);
		} else {
			int i;
			printf("CHild proc id: %d \n",pid);
			for(i = 0; i < 5; ++i){
				puts("wait...");
				sleep(5);
			}
		}
	}
	return 0;
}
