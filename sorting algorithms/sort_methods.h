/*
 * sort_methods.h
 *
 *  Created on: 2016Äê11ÔÂ24ÈÕ
 *      Author: Administrator
 */

#ifndef SORT_METHODS_H_
#define SORT_METHODS_H_
#include "array_generation.h"



void quicksort_lomuto(PARR pArr,int low, int high);
int partition_lomuto(PARR pArr,int low, int high);

void quicksort_hoare(PARR pArr,int low, int high);
int partition_hoare(PARR pArr,int low, int high);

void quicksort_new(PARR pArr,int low, int high);
int partition_new(PARR pArr,int low, int high);

void heapsort(PARR pArr);
void heap_insert(PARR pArr,int i);
int heap_delete(PARR pArr,int* plength);
void heapify_down(PARR pArr,int i,int length);

void mergeSort(PARR pArr,int low,int high);
void merge(PARR pArr,int low,int mid,int high);

#endif /* SORT_METHODS_H_ */
