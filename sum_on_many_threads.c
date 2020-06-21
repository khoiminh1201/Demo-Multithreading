#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct sum_runner_struct {
	long long limit;
	long long answer;
};

// Ham luong de tao tong tu 0 den N
void* sum_runner(void* arg)
{
	struct sum_runner_struct *arg_struct =
			(struct sum_runner_struct*) arg;

	long long sum = 0;
	long long i = 0;
	for ( ;i <= arg_struct->limit; i++) {
		sum += i;
	}

	arg_struct->answer = sum;

	pthread_exit(0);
}

int main(int argc, char **argv)
{
	int i=0;
	if (argc < 2) {
		printf("Usage: %s <num 1> <num 2> ... <num-n>\n", argv[0]);
		exit(-1);
	}
	int num_args = argc - 1;

	struct sum_runner_struct args[num_args];

	// Launch thread
	pthread_t tids[num_args];
	for (i=0; i < num_args; i++) {
		args[i].limit = atoll(argv[i + 1]);
	
	//Tao thuoc tinh pthread
		pthread_attr_t attr;
	//Tro pthread den du lieu
		pthread_attr_init(&attr);
		pthread_create(&tids[i], &attr, sum_runner, &args[i]);
	}

	// Wait cho den khi thread hoan thanh\
	

	for (i=0; i < num_args; i++) {
		pthread_join(tids[i], NULL);
		printf("Sum for thread %d is %lld\n",
				i, args[i].answer);
	}
}
