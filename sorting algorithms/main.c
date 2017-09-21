/*
 * main.c
 *
 *  Created on: 2016Äê11ÔÂ24ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_generation.h"
#include "sort_methods.h"
#include <sys/time.h>


int main(void){
	printf("N\t Runtime\t\n");
	for(int N=1000;N<31000;N+=1000){
		double total=0;
		for(int count=0;count<5;count++){
			ARR a;
			init_regular_array(&a,N);
			//init_ascending_array(&a,N);
			//init_descending_array(&a,N);
			//init_repeating_array(&a,N);
			//init_same_element_array(&a,N);

			struct timeval start, finish;
			/*the variables "start" and "finish" can store system time. They have two attributes:
			 tv_sec and tv_usec, which can store second and microsecond respectively
			 */

			gettimeofday(&start, NULL);

			quicksort_lomuto(&a,0,a.length-1);
			//quicksort_hoare(&a,0,a.length-1);
			//quicksort_new(&a,0,a.length-1);
			//mergeSort(&a,0,a.length-1);
			//heapsort(&a);
			gettimeofday(&finish, NULL);
			double duration=(finish.tv_sec-start.tv_sec)*1000000+(finish.tv_usec-start.tv_usec);
			total+=duration;
			free_array(&a);
		}



		printf("%d\t %f\n",N,total/5);

	}



	return 0;
}
