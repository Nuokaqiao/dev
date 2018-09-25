/*************************************************************************
	> File Name: mutex.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年08月25日 星期六 13时30分04秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 100

void *thread_inc(void *arg);
void *thread_des(void *arg);

long long sum = 0;
pthread_mutex_t mutex;

int main(int argc,char **argv)
{
	pthread_t thread_id[NUM_THREAD];
	int i;

	pthread_mutex_init(&mutex,NULL);

	printf("sizeof long long: %ld \n",sizeof(long long));
	for(i = 0; i < NUM_THREAD; ++i){
		if(i % 2)
			pthread_create(&thread_id[i],NULL,thread_inc,NULL);
		else
			pthread_create(&thread_id[i],NULL,thread_des,NULL);
	}

	for(i = 0; i < NUM_THREAD; ++i){
		pthread_join(thread_id[i],NULL);

	}
	printf("result: %lld \n",sum);
	pthread_mutex_destroy(&mutex);
	return 0;
}

void *thread_inc(void *arg)
{
	int i;
	pthread_mutex_lock(&mutex);
	for(i = 0; i < 50000000; ++i)
		sum += 1;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void *thread_des(void *arg)
{
	int i; 
	for(i = 0; i < 50000000; ++i){
		pthread_mutex_lock(&mutex);
		sum -= 1;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
