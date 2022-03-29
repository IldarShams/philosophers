#include "philo.h"

int main()
{
	struct timeval	start_time;
	struct timeval	end_time;

	gettimeofday(&start_time, NULL);

	usleep(10000);

	gettimeofday(&end_time, NULL);
	printf("current_timestamp: %ld\n", start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
	printf("start_time:%ld sec, %ld usec\n", start_time.tv_sec, start_time.tv_usec);
	printf("end_time:%ld sec, %ld usec\n", end_time.tv_sec, end_time.tv_usec);
	printf ("diff: %ld\n", (end_time.tv_sec - start_time.tv_sec) * 1000
		+ (end_time.tv_usec - start_time.tv_usec) / 1000);
}
