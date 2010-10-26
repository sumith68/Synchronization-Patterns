/*Multiplex: it allows multiple threads to run in the critical section at the same time.Here we initialise the semaphore to the number of threads*/

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sem;
int count=0;
void* fun1(void *arg)
{
	sem_wait(&sem);
	count=count+1;
	sleep(1);
	printf("%d\n",count);
	sem_post(&sem);
}
void* fun2(void *arg)
{
	sem_wait(&sem);
	count=count+1;
	sleep(1);
	printf("%d\n",count);
	sem_post(&sem);

}	

void* fun3(void *arg)
{
	sem_wait(&sem);
	count=count+1;
	sleep(1);
	printf("%d\n",count);
	sem_post(&sem);

}	

main()
{
	pthread_t t1,t2,t3;
	sem_init(&sem,0,2);
	pthread_create(&t1,0,fun1,0);
	pthread_create(&t2,0,fun2,0);
	pthread_create(&t3,0,fun3,0);
	pthread_join(t1,0);
	pthread_join(t2,0);
	pthread_join(t3,0);


}
