/* signaling: here one thread sends a signal to another thread indicate that something has happend */
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sem;
void* fun1(void *arg)
{
	printf("%s\n",(char*)arg);
	sem_post(&sem);	
}
void* fun2(void *arg)
{
	sem_wait(&sem);
	printf("%s\n",(char*)arg);
}	

main()
{
	pthread_t t1,t2;
	sem_init(&sem,0,0);
	pthread_create(&t1,0,fun1,"fun1"); /*create two threads t1&t2 */
	pthread_create(&t2,0,fun2,"fun2");
	pthread_join(t1,0);
	pthread_join(t2,0);
}
