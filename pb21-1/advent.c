#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "advent.h"


#include <stdio.h>
#include <stdlib.h>

int* get_i(pos* p){
    return &(p->i);
}

int* get_j(pos* p){
    return &(p->j);
}

void init_vector(Vector *vec){
    vec->size = 0;
    vec->capacity = 4;  // initial capacity
    vec->data = (pos*)malloc(vec->capacity * sizeof(pos)); // allocate memory
}

int get_size(Vector* vec){
	return vec->size;
}

void push(Vector *vec,pos new_pos){

    // if the vector is full, double its capacity
    if (vec->size == vec->capacity) {
        vec->capacity *= 2; 
        vec->data = (pos*)realloc(vec->data, vec->capacity * sizeof(pos)); // Reallocate memory
    }
    vec->data[vec->size] = new_pos;  // add the new pos
    vec->size++;                  
}


pos pop(Vector *vec){
    if (vec->size == 0) { // error handling
        printf("Error: Cannot pop from an empty vector.\n");
        return (pos){-1, -1};
    }
    pos p = vec->data[vec->size - 1];  // Get the last element
    vec->size--;                                // Decrease the size, effectively removing the element
    return p;                         // Return the popped value
}

void free_vector(Vector *vec){
    free(vec->data);  // Free the allocated memory
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}


void check_neighbours(int* i,int* j,char*** array_p, Vector* WL_p,int rows, int cols){

    // printf("checking neighbours of array[%d][%d]\n", (*i), (*j));
	// handle corners : 
	if ((*i)!=0){
        int new_i = *i - 1;
		check_nei(&new_i, j, array_p, WL_p);
	} 
	if ((*i)!=rows-1){
        int new_i = *i + 1;
		check_nei(&new_i, j, array_p, WL_p);
	}
	if ((*j)!=0){
        int new_j = *j - 1;
		check_nei(i, &new_j, array_p, WL_p);
	}
	if ((*j)!=cols-1){
        int new_j = *j + 1;
		check_nei(i, &new_j, array_p, WL_p);
	}
};

void check_nei(int* x,int* y,char*** array_p, Vector* WL_p){
	if ((*array_p)[(*x)][(*y)] == '.'){ // new possibility : increment res
        (*array_p)[(*x)][(*y)] = 'O';
		pos nei = {(*x), (*y)};
        // printf("Good new neighbour at array[%d][%d]\n", (*x), (*y));
		push(WL_p, nei); // if good, add neighbour to the waiting list;
	} 
    // good neighbour but already counted
    else if ((*array_p)[(*x)][(*y)] == 'O') {
        //pos nei = {(*x), (*y)};
        // printf("Good old neighbour at array[%d][%d]\n", (*x), (*y));
		//push(WL_p, nei); 
    } 
    
    else {
        //printf("Wrong neighbour : %c\n", (*array_p)[(*x)][(*y)] );
    }
}