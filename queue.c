/* Here the leader and follower aree two semaphore variables. here when the leader arrives,it checks too see if threre is a follower waiting.If so they can both proceed. Otherwisse it waits . similar in the case of follower*/
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t leader,follower;
int n;
void* fun1(void *arg)
{
	printf("entering the leader1\n");
	sem_post(&follower);
	sem_wait(&leader);
	printf("leader1\n");
}
void* fun2(void *arg)
{
	printf("entering the follower1\n");
	sem_post(&leader);
	sem_wait(&follower);
	printf("follower1\n");
}	

void* fun3(void *arg)
{
	printf("entering the leader2\n");
	sem_post(&leader);
	sem_wait(&follower);
	printf("leader2\n");
}	

void* fun4(void *arg)
{
	printf("entering the follower2\n");
	sem_post(&leader);
	sem_wait(&follower);
	printf("follower2\n");
}	

main()
{
	n=4;
	pthread_t t[n];
	sem_init(&leader,0,0);
	sem_init(&follower,0,0);
	pthread_create(&t[0],0,fun1,0);
	pthread_create(&t[1],0,fun2,0);
//	pthread_create(&t[2],0,fun1,0);
//	pthread_create(&t[3],0,fun2,0);
	pthread_join(t[0],0);
	pthread_join(t[1],0);
//	pthread_join(t[2],0);
//	pthread_join(t[3],0);
}
