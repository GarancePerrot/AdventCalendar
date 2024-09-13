#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "advent.h"

void get_hash(char* token, int* ps){

    int cv = 0;  // current value
    int c; // current character's ASCII code
    for (int i=0; i< strlen(token); i++){ //iterate over all characters
                                            // perform hash algo 
        //printf("char : %c\n", token[i]);
        c = token[i];          
        cv += c;
        cv *= 17; 
        cv %= 256;
    }
    *ps = cv;  // updates partial sum
    // printf("ps : %d\n", *ps);
}