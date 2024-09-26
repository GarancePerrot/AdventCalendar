
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "advent.h"

int main(int argc, char* argv[]){
    FILE *file; 
    char line[256];                         //store each line
    
    int id = 0;                        // for game impossible or not
    int sum = 0;                           // for global sum
    int max_red = 12 ;
    int max_green = 13;
    int max_blue = 14;
    int c = 0;

    int game_max_red = 0;
    int game_max_green = 0;
    int game_max_blue = 0;
    int game_power = 0;
    int sum_powers = 0;

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
        game_max_red = 0;
        game_max_green = 0;
        game_max_blue = 0;
        game_power = 0;
        c+=1; // game number
        id = 0;
        
        // printf("Reading line : %s\n", line);

        // here it stops working after printing the first line 
        
        // printf("debug");
        get_num(line, &id, max_red, max_green, max_blue, &d1, &d2, &game_max_red, &game_max_green, &game_max_blue);        

        game_power = game_max_blue * game_max_green * game_max_red;

        sum_powers += game_power;

        
        if (id==0){         // game was possible
            sum += c;       // add to global sum
            // printf("Current sum : %d\n", sum);
        }
        
    }
    // printf("The sum of IDs is : %d\n", sum);

    printf("The sum of game powers is %d\n", sum_powers);

    fclose(file);
    
    return 0; 
}