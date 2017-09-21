/*
 * quicksort.c
 *
 *  Created on: 2016Äê11ÔÂ24ÈÕ
 *      Author: Administrator
 */
#include <stdio.h>
#include <stdlib.h>

#include "array_generation.h"
#include "sort_methods.h"


//Quicksort with Lomuto partition scheme
void quicksort_lomuto(PARR pArr,int low, int high){
	if(low<high&&low>=0&&high<pArr->length){
		//divide the array and return the location for the pivot element
		int mid=partition_lomuto(pArr,low,high);

		quicksort_lomuto(pArr,low,mid-1);//recursive function call
		quicksort_lomuto(pArr,mid+1, high);

	}
}


int partition_lomuto(PARR pArr,int low, int high){
	int pivot=pArr->pBase[high];

	//This algorithm uses an index i to point to the end of the left part
	int i=low-1;

	int temp;//a temporary variable used when swaping array elements

	//if Array[j]<=pivot, then increase i and swap Array[i] and Array[j]
	for(int j=low;j<high;j++){
		if(pArr->pBase[j]<=pivot){
			i++;
			temp=pArr->pBase[i];
			pArr->pBase[i]=pArr->pBase[j];
			pArr->pBase[j]=temp;
		}
	}
	//Swap Array[i+1] and Array[high]
	//Thus the position of pivot element is i+1
	temp=pArr->pBase[i+1];
	pArr->pBase[i+1]=pArr->pBase[high];
	pArr->pBase[high]=temp;
	return (i+1);
}

//Quicksort with Hoare partition scheme
void quicksort_hoare(PARR pArr,int low, int high){
	if(low<high&&low>=0&&high<pArr->length){
		int index=partition_hoare(pArr,low,high); //divide the array and return an index
		quicksort_lomuto(pArr,low,index);
		quicksort_lomuto(pArr,index+1, high);

	}
}

int partition_hoare(PARR pArr,int low, int high){
	int pivot=pArr->pBase[low];
	int i=low-1;
	int j=high+1;
	int temp;//a temporary variable used when swaping array elements

	/* i and j move toward each other, until they detect an inversion:
	 * a pair of elements, one greater or equal than the pivot,
	 * one less than or equal, that are in the wrong order
	 * relative to each other.
	 * */
	while(1){
		do{i++;}while(pArr->pBase[i]<pivot);
		do{j--;}while(pArr->pBase[j]>pivot);
		if(i<j){
			temp=pArr->pBase[i];
			pArr->pBase[i]=pArr->pBase[j];
			pArr->pBase[j]=temp;
		}else{ //when i=j or i>j, the while-loop ends
			break;
		}
	}
	//the final index is j instead of i, otherwise it might incur endless loop.
	return j;

}

//Quicksort with a new partition scheme
void quicksort_new(PARR pArr,int low, int high){
	if(low<high&&low>=0&&high<pArr->length){
		int mid=partition_new(pArr,low,high); //divide the array and return an index
		quicksort_lomuto(pArr,low,mid-1);
		quicksort_lomuto(pArr,mid+1, high);

	}
}

int partition_new(PARR pArr,int low, int high){
	int pivot=pArr->pBase[low];

	//use two indices(i and j) which initially point to the start
	//and end of the array, respectively.
	int i=low;
	int j=high;
	/*At first, the algorithm compares A[j] with the pivot:
	 *while A[j]>=pivot, j decreases by 1, until A[j]<pivot.Let A[i]=A[j].
	 * Then compares A[i] with the pivot:
	 *while A[i]<=pivot, i is incremented, until A[i]>pivot.Let A[j]=A[i].
	 * Then compares A[j] with the pivot....
	 * */
	while(i<j){
		while(i<j&&pArr->pBase[j]>=pivot){
			j--;
		}
		pArr->pBase[i]=pArr->pBase[j];
		while(i<j&&pArr->pBase[i]<=pivot){
			i++;
		}
		pArr->pBase[j]=pArr->pBase[i];
	}
	pArr->pBase[i]=pivot;
	return i;
}

/*The heap property is designed to be: ¡°the timestamp of a parent node
 * is always larger than or equal to the timestamp of any of its kids¡±.
 * */
void heapsort(PARR pArr){
	int heapLength=pArr->length;
	for(int i=1;i<pArr->length;i++){
		heap_insert(pArr,i);
	}
	for(int j=pArr->length-1;j>0;j--){
		pArr->pBase[j]=heap_delete(pArr,&heapLength);
	}
}


void heap_insert(PARR pArr,int i){//parent nodes always have a larger timestamp than its kids
	if(i==0){
		return;
	}
	if(pArr->pBase[i]>pArr->pBase[(i-1)/2]){
		int temp=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[(i-1)/2];
		pArr->pBase[(i-1)/2]=temp;
		heap_insert(pArr,(i-1)/2);
	}
}

int heap_delete(PARR pArr,int* plength){
	int root=pArr->pBase[0];
	pArr->pBase[0]=pArr->pBase[(*plength)-1];
	(*plength)--;
	heapify_down(pArr,0,(*plength));
	return root;
}

void heapify_down(PARR pArr,int i,int length){
	//if the node doesn't exist or if it has no children nodes
	if(i>length-1||(2*i+1)>length-1){
		return;
	}

	//if the node only has one child
	else if(2*i+1==length-1){
		if(pArr->pBase[i]<pArr->pBase[2*i+1]){
			int temp=pArr->pBase[i];
			pArr->pBase[i]=pArr->pBase[2*i+1];
			pArr->pBase[2*i+1]=temp;
		}
	}

	//if the node has two children nodes
	else{
		if(pArr->pBase[i]>=pArr->pBase[2*i+1]&&pArr->pBase[i]>=pArr->pBase[2*i+2]){
			return;
		}
		else if(pArr->pBase[2*i+1]>=pArr->pBase[2*i+2]){
			int temp=pArr->pBase[i];
			pArr->pBase[i]=pArr->pBase[2*i+1];
			pArr->pBase[2*i+1]=temp;
			heapify_down(pArr,2*i+1,length);
		}
		else{
			int temp=pArr->pBase[i];
			pArr->pBase[i]=pArr->pBase[2*i+2];
			pArr->pBase[2*i+2]=temp;
			heapify_down(pArr,2*i+2,length);
		}
	}
}


void mergeSort(PARR pArr,int low,int high){
	if(low>=high){
		return;
	}
	int mid=(low+high)/2;
	mergeSort(pArr,low,mid);
	mergeSort(pArr,mid+1,high);
	merge(pArr,low,mid,high);
}

void merge(PARR pArr,int low,int mid,int high){
	int n1=mid-low+1;
	int n2=high-mid; //n1 and n2 stores the length of two subarrays
	int *left=(int *)malloc((n1+1)*sizeof(int));
	int *right=(int *)malloc((n2+1)*sizeof(int));
	if(left==NULL||right==NULL){
		exit(-1);
	}
	for(int i=0;i<n1;i++){
		left[i]=pArr->pBase[low+i];
	}
	left[n1]=RAND_MAX; //the last element in each subarray is a very large number
	for(int i=0;i<n2;i++){
		right[i]=pArr->pBase[mid+1+i];
	}
	right[n2]=RAND_MAX;
	int i=0;
	int j=0;
	for(int k=low;k<=high;k++){
		if(left[i]<=right[j]){
			pArr->pBase[k]=left[i];
			i++;
		}
		else{
			pArr->pBase[k]=right[j];
			j++;
		}
	}
	free(left);
	free(right);

}
