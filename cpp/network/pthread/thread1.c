/*************************************************************************
	> File Name: thread1.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月25日 星期六 10时55分55秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_main(void *arg);

int main(int argc,char **argv)
{
	pthread_t t_id;
	int thread_param = 5;

	if(pthread_create(&t_id,NULL,thread_main,(void*)&thread_param) != 0){
		puts("pthread_create() error");
		return -1;
	}
	sleep(3);
	puts("end of main");
	return 0;
}

void* thread_main(void *arg)
{
	int i;
	int cnt = *((int *)arg);
	for(i = 0; i < cnt; ++i){
		sleep(1);
		puts("running thread");
	}
	return NULL;
}
