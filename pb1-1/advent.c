
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "advent.h"

// I prefer to use pointers for the ints in this function for safety
void get_num(char* line, char* rev, int* f, int* l, int* num){

	int i = 0;                  // extract first digit from line
	while (line[i] != '\0'){  
		if(isdigit(line[i])){
			*f = line[i] - '0'; // convert character into digit using ASCII values
			break;
		}
		i++;
		if (line[i]== '\0'){
			printf("no first digit was found\n");
		}
	}


	// we do the same with the reversed line to dinf the last digit of line
	i = 0; 
	while (rev[i] != '\0'){  
		//printf("%c", rev[i]); //debugging
		if(isdigit(rev[i])){
			*l = rev[i] - '0'; 
			break;
		}
		i++;
		if (rev[i]== '\0'){
			printf("no last digit was found\n");
		}
	}
               
	(*num) = 10 * (*f) + (*l);          // combine result
	printf("Number formed : %d", (*num));
}
