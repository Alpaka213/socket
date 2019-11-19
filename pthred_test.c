#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func_thread(void *);
//void * : java = object 
int main(){
	int status;
	pthread_t thread_id;
	pthread_create(&thread_id, NULL,func_thread,NULL);
	printf("thread %x is created \n",thread_id);
	printf("main thread END\n");
	return 0;

}


void *func_thread(void *argv)
{
	int i=0;
	while (i<10)
	{
		i++;
		printf("%thread %d excuting\n",i);
	}
}

