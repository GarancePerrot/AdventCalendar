
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <math.h>

#include "advent.h"

int main(int argc, char* argv[]){
	FILE *file; 

	file = fopen("input.txt", "r"); 
	if (file == NULL){                     //error handling
		printf("Error: file not found\n");
		return 1;
	}

	// determining the dimension of the array
	int rows = 0, cols = 0;
	char line[200];

	while (fgets(line, sizeof(line), file) != NULL) {
		rows++;
		cols = strlen(line); 
	}
	//printf("rows, cols : %d, %d\n", rows, cols);

	// dynamic allocatiojn for the array

	char** array = (char**)malloc(rows * sizeof(char*));
	if (array == NULL) {
		printf("Error allocating memory.\n");
		return 1;
	}

	for (int i = 0; i < rows; i++) {
		array[i] = (char*)malloc((cols+1)*sizeof(char)); // 
		if (array[i] == NULL) {
			printf("Error allocating memory.\n");
			return 1;
		}
	}

	// copying file content in the array

	rewind(file); // go back to the beginning of the file

	for (int i = 0; i < rows; i++) {
		fgets(line, sizeof(line), file);
		int len = strlen(line);
		// remove the newline character if present
		if (line[len - 1] == '\n') {
			line[len - 1] = '\0';
		}

		// copy the line into the array
		strcpy(array[i], line);
	}

	fclose(file);

	// // debug : 
	// for (int i= 0; i< rows ; i++){
	// 	for (int j=0; j< cols; j++){
	// 		printf(" print : %c \n", array[i][j]);
	// 	}
	// }

	//printf("array[5][5] : %c", array[5][5]);

	// now we can get to the interesting part : 
	
 	Vector waiting_list; // Vector struct defined in advent.h
	// the waiting list will store garden plots which are waiting to check their neighbours
	//  i.e waiting list = positions marked as 'O' in the assignment

	init_vector(&waiting_list);

	Vector WL_2;
	init_vector(&WL_2);

	int i= 0;
	int j =0;
	int flag = 0;
	pos start = {-1,-1};


	// 1st step : get the starting position : 
	for (i = 0; i < rows; i++){
		if (flag){
			break; 
		}
		
		for (j = 0; j < cols; j++){

			if (array[i][j] == 'S'){
				start.i = i;   //store start position
				start.j = j;
				// modify start position so that it counts as a usual garden plot for further iterations
				array[i][j] = '.'; 
				flag = 1;
				break;
			}
		}
	}

	//printf("start : %d, %d\n", start.i, start.j);
	
	push(&waiting_list, start);  // push start position in the waiting list
    

	// further steps : loop until nb_steps is 0 

	
	
	int counter = 32;   // counter should be nb_steps/2 because we do two steps in one iteration
	int len_1 = 0, len_2 = 0;

	//alternating between two waiting lists to ensure that we check all the neighbours 
	// before looking into the neighbours of a neighbour

	while (counter > 0) { // while the waiting list is not empty
		
		len_1 = get_size(&waiting_list);

		while (len_1 > 0){
			pos p = pop(&waiting_list);
			int  ii = *get_i(&p) ;
			int jj = *get_j(&p) ; 
			array[ii][jj] = '.'; // set it to possible position again (has been changed to 'O' previously)
			if (ii != -1 && jj != -1){ // error check 
				check_neighbours(get_i(&p),get_j(&p),&array, &WL_2,rows, cols); // check neighbours of pos(i,j):
			}
			else {
				printf("Error on popped element\n");
			}

			len_1 = get_size(&waiting_list);
			len_2 =  get_size(&WL_2);
			
			// printf("len_1 : %d\n", len_1);
			// printf("len_2 : %d\n", len_2);
		}

		len_2 = get_size(&WL_2);
		while (len_2 > 0){
			
			pos p = pop(&WL_2);
			int  ii = *get_i(&p) ;
			int jj = *get_j(&p) ; 
			array[ii][jj] = '.'; // set it to possible position again (has been changed to 'O' previously)
			if (ii != -1 && jj != -1){ // error check 
				check_neighbours(get_i(&p),get_j(&p),&array, &waiting_list,rows, cols); // check neighbours of pos(i,j):
			}

			len_1 = get_size(&waiting_list);
			len_2 =  get_size(&WL_2);
			
			// printf("len_1 : %d\n", len_1);
			// printf("len_2 : %d\n", len_2);
		}

		counter --;
	}


	// free allocated memory
	free_vector(&waiting_list);
	for (int i = 0; i < rows; i++) {
		free(array[i]);
	}
	free(array);

	printf("The result is : %d\n.", len_1);
	return 0; 
}
