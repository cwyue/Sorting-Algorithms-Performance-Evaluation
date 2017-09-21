/*
 * array_generation.c
 *
 *  Created on: 2016Äê11ÔÂ24ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_generation.h"


//All items in this array are random integers
void init_regular_array(PARR pArr,int N){
	srand(time(0));
	if(N<=0){
		return;
	}
	pArr->length=N;
	pArr->pBase=(int*)malloc(N*sizeof(int));
	if(pArr->pBase==NULL){
		exit(-1);
	}
	for(int i=0;i<N;i++){
		pArr->pBase[i]=rand();
	}
}


//All items in this array are already sorted in ascending order.
void init_ascending_array(PARR pArr,int N){

	if(N<=0){
		return;
	}
	pArr->length=N;
	pArr->pBase=(int*)malloc(N*sizeof(int));
	if(pArr->pBase==NULL){
		exit(-1);
	}
	for(int i=0;i<N;i++){
		pArr->pBase[i]=i;
	}
}


//All items in this array are already sorted in descending order.
void init_descending_array(PARR pArr,int N){

	if(N<=0){
		return;
	}
	pArr->length=N;
	pArr->pBase=(int*)malloc(N*sizeof(int));
	if(pArr->pBase==NULL){
		exit(-1);
	}
	int j=N-1;
	for(int i=0;i<N;i++){
		pArr->pBase[i]=j;
		j--;
	}
}


//All items are random integers and they occur repeatedly and successively.
void init_repeating_array(PARR pArr,int N){
	srand(time(0));
	if(N<=0){
		return;
	}
	pArr->length=N;
	pArr->pBase=(int*)malloc(N*sizeof(int));
	if(pArr->pBase==NULL){
		exit(-1);
	}
	int i=0;
	while(i<N){
		int repeat_count=rand()%10+1;
		//The count number of times that one item repeats is within [1,10].

		int repeat_element=rand();
		//Items in this array are random integers.

		int j=0;
		while(j<repeat_count&&i<N){
			pArr->pBase[i]=repeat_element;
			j++;
			i++;
		}
	}

}

//generate an array whose items are random integers within [0,range-1].
void init_repeating_array_noOrder(PARR pArr,int N,int range){
	srand(time(0));
	if(N<=0){
		return;
	}
	pArr->length=N;
	pArr->pBase=(int*)malloc(N*sizeof(int));
	if(pArr->pBase==NULL){
		exit(-1);
	}

	 //One value might occur for several times but
	//they don't necessarily locate within a cluster.
	for(int i=0;i<N;i++){
		pArr->pBase[i]=rand()%range;
	}
}

//generate an array whose items are all zero.
void init_same_element_array(PARR pArr,int N){
	if(N<=0){
		return;
	}
	pArr->length=N;
	pArr->pBase=(int*)malloc(N*sizeof(int));
	if(pArr->pBase==NULL){
		exit(-1);
	}
	for(int i=0;i<N;i++){
		pArr->pBase[i]=0;
	}
}

//print the array items in the console.
void print_array(PARR pArr){
	if(pArr==NULL){
		return;
	}
	for(int i=0;i<pArr->length;i++){
		printf("%d ",pArr->pBase[i]);
	}
	printf("\n");
}


//free the storage for this array
void free_array(PARR pArr){
	if(pArr->pBase!=NULL){
		free(pArr->pBase);
	}
}
