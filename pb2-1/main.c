
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "advent.h"

int main(int argc, char* argv[]){
    FILE *file; 
    char line[256];                         //store each line
    
    int id = -1;                        // for game impossible or not
    int sum = 0;                           // for global sum
    int max_red = 12 ;
    int max_green = 13;
    int max_blue = 14;
    int c = 0;

    int d1 = 0;
    char d2 = 'o';


    file = fopen("input.txt", "r"); 
    if (file == NULL){                     //error handling
        printf("Error: file not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)){  //reads file line by line

        d1 = 0;
        d2 = 'o';
        c+=1; // game number
        
        // printf("Reading line : %s\n", line);

        // here it stops working after printing the first line 
        
        // printf("debug");
        get_num(line, &id, max_red, max_green, max_blue, &d1, &d2);        

        
        if (id==0){         // game was possible
            sum += c;       // add to global sum
            // printf("Current sum : %d\n", sum);
        }
        
    }
    printf("Result is : %d\n", sum);

    fclose(file);
    
    return 0; 
}