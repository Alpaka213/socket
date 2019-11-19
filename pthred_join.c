#include <stdio.h>
#include <pthread.h>

void *do_sum(void *); // thread runchi function
//  parameter sum print

int main(){
	pthread_t thread_id[3];
	int status[3];
	int a = 4; // 1 thread parameter
	int b = 5; // second thread parameter
	int c = 6; // third thread parameter

	status[0] = pthread_create(&thread_id[0],NULL,do_sum, (void *)&a);
	status[1] = pthread_create(&thread_id[1],NULL,do_sum, (void *)&b);
	status[2] = pthread_create(&thread_id[2],NULL,do_sum, (void *)&c);
	pthread_join(thread_id[0], (void **)&status[0]);
	pthread_join(thread_id[1], (void **)&status[1]);
	pthread_join(thread_id[2], (void **)&status[2]);
	printf("Main Thread END\n");

}

void *do_sum(void *arg)
{
	int max = *((int *)arg);
	int sum =0;
	int i=0;
	for (i =0;i<=max;i++){
		sum += i;	
		printf("%d ADD %d \n",max,i);
	}
	printf("1~ %d sum,%d",max,sum);
}
