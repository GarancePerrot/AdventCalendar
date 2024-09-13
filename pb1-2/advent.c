#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "advent.h"

struct letter_digit digits[] = {  
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};

// same for digits in reverse 

struct letter_digit reversed_digits[] = {  
    {"orez", 0},
    {"eno", 1},
    {"owt", 2},
    {"eerht", 3},
    {"ruof", 4},
    {"evif", 5},
    {"xis", 6},
    {"neves", 7},
    {"thgie", 8},
    {"enin", 9}
};


void check_for_digit(struct letter_digit dict[], char* line, int* f){   // searches the first digit in the line (litteral or digit form)
    int i = 0;  // iterate over characters if the line
    int ii = 0;  // not lose track of i;
    int j = 0;       // iterate over the digits of the dict (from 0 to 9)  
    int k = 0;       // iterate over characters of a digit from the dict  
	while (line[i] != '\0'){ 
        (*f) = -1;
		if(isdigit(line[i])){
			*f = line[i] - '0';
            //printf("Found under digit form : %d\n", *f); 
			break;
		} else {                  // Here we add the new check for letter digits ! 
            //printf("Entering letter-digit check for %c\n", line[i]);
            for (j=0; j<10; j++) {  // check for all the digits
                ii = i;
                k = 0;
                //printf("Looking for digit %s\n", dict[j].key); 

                while ((ii<strlen(line)) && (k < strlen(dict[j].key)) && (line[ii] == dict[j].key[k])){ // check characters one by one 
                    //printf("comparing %c with %c\n",line[ii],  dict[j].key[k]);
                    //printf("current value of k : %d\n",k);
                    if ((k+1)== strlen(dict[j].key)){  // stop when word was found
                        (*f) = dict[j].value; 
                        //printf("Found under litteral form : %d\n", *f);
                        break;
                    }
                    k++; // continue comparing with letter-digits
                    ii++;
                    //printf("ii : %d\n", ii);
                    //printf("k : %d\n", k);
                }
            }
        } // end letter-digit check
        if ( (*f) != -1){
            break;
        }
        i++;  // check for all characters of the line
		if (line[i]== '\0'){
			puts("No first digit was found\n");
		}
	}

}

void get_num(char* line, char* rev, int* f, int* l, int* num){

    check_for_digit(digits, line,f);

    if(*f == -1){
        puts("No first digit found\n");
        return;
    }

    //puts("Checking for last digit : \n");
    check_for_digit(reversed_digits, rev, l);

    if(*l == -1){
        puts("No last digit found\n");
        return;
    }

	(*num) = 10 * (*f) + (*l);          // combine result
	//printf("Number formed : %d\n", (*num));
}
