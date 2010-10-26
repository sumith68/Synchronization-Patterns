/* Rendezvous: here Thread A has to wait for thread B and vice versa
		here a1 happens before b2 and b1 happens before a2 */
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t a,b;
void* fun1(void *arg)
{
	printf("a1\n");
	sem_post(&a);
	sem_wait(&b);
	printf("a2\n");
}
void* fun2(void *arg)
{
printf("b1\n");
sem_post(&b);
sem_wait(&a);
printf("b2\n");

}	

main()
{
	pthread_t t1,t2;
	sem_init(&a,0,0);
	sem_init(&b,0,0);
	pthread_create(&t1,0,fun1,0);
	pthread_create(&t2,0,fun2,0);
	pthread_join(t1,0);
	pthread_join(t2,0);
}w
