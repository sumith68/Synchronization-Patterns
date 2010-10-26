#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t leader,follower,mutex,rend;
int fol,lead;
void *fun1(void *arg)
{
	sem_wait(&mutex);
	if(fol>0){
		fol--;
		sem_post(&follower);
	}
	else{
		lead++;
		sem_post(&mutex);
		sem_wait(&leader);
	}
	printf("leader\n");
	sem_wait(&rend);
	sem_post(&mutex);
}

void *fun2(void *arg)
{
	sem_wait(&mutex);
	if(lead>0){
		lead--;
		sem_post(&leader);
	}
	else{
		fol++;
		sem_post(&mutex);
		sem_wait(&follower);
	}
	printf("follower\n");
	sem_post(&rend);
}




main()
{
	pthread_t t1,t2;
	sem_init(&leader,0,0);
	sem_init(&follower,0,0);
	sem_init(&mutex,0,1);
	sem_init(&rend,0,0);
	pthread_create(&t1,0,fun1,0);
	pthread_create(&t2,0,fun2,0);
	pthread_join(t1,0);
	pthread_join(t2,0);
}















