/*
 * array_generation.h
 *
 *  Created on: 2016Äê11ÔÂ24ÈÕ
 *      Author: Administrator
 */

#ifndef ARRAY_GENERATION_H_
#define ARRAY_GENERATION_H_

typedef struct Array{
	int length;
	int *pBase;
}ARR,*PARR;

//generate an array whose items are random integers
void init_regular_array(PARR pArr,int N);

//generate an array whose items are already sorted in ascending order
void init_ascending_array(PARR pArr,int N);

//generate an array whose items are already sorted in descending order
void init_descending_array(PARR pArr,int N);

/*generate an array whose items are random integers and they occur repeatedly and successively.
 * The number of times that one item repeats is within [1,10].
 * For instance, it may generate an array like [34,34,34,7,7,7,7,7,7,65,65,65,65,2,2]
 */
void init_repeating_array(PARR pArr,int N);

/*generate an array whose items are random integers within [0,range-1]
 * where "range" is a given integer.
 * One value might occur for several times but they don't necessarily locate within a cluster.
 * For instance, given range=5, it may generate an array like [1,4,0,1,0,4,2,1,2]
 */
void init_repeating_array_noOrder(PARR pArr,int N,int range);

void init_same_element_array(PARR pArr,int N);

//show the items in the array
void print_array(PARR pArr);

//free the storage for this array
void free_array(PARR pArr);
#endif /* ARRAY_GENERATION_H_ */
