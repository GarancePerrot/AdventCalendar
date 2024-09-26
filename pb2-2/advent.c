
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "advent.h"

int convertTwoCharsToNumber(char* ch1, char* ch2) {
    if (isdigit(*ch1) && isdigit(*ch2)) {
        return (*ch1 - '0') * 10 + (*ch2 - '0');
    } else {
        printf("invalid conversion into number of %c and %c \n", *ch1, *ch2);
        return -1; // Indicate invalid characters
    }
}





void get_num(char* line, int* id, int max_red, int max_green, int max_blue, int* d1, char* d2, int* game_max_red, int* game_max_green, int* game_max_blue){

    int flag = 1;  // for the sets : 0 will be not ok and 1 will be ok

	int i = 0, j=0;                  // extract digit id from line
	
    // start after 'Game x: '
    while(line[i]!=':' && line[i] != '\0'){  
        i++;
    }
    i++;
	while (line[i] != '\0'){         //over the game : 
		//printf("%c", line[i]); //debugging
        flag = 0;  // initialize again for new set
        i++;
        // printf("%c\n", line[i] );
        j = i;

        while (line[j] != ';' && line[j] != '\0'){  // over a set :

            // printf("%c\n", line[j] );

            if (isdigit(line[j]) && !isdigit(line[j-1])){ 
                
                *d1 = line[j]-'0'; 
                *d2 = line[j+2];
                
                if (isdigit(line[j+1])){
                    *d1 = convertTwoCharsToNumber(&line[j], &line[j+1]);
                    *d2 = line[j+3];
                    
                }


                // printf("d1 : %d  ",*d1);
                // printf("d2 : %c\n", *d2);

                if (*d2=='r'){
                    if ((*d1)<=(max_red)){  //ok for red for this set
                        flag +=1 ;  
                    }
                    else{
                        flag = 0;   // we can return directly 
                        *id = -1;   // means that a set was impossible
                    }

                    if ((*d1)>(*game_max_red)){   // updating max 
                        (*game_max_red) = (*d1);
                    }
                }
                else if (*d2=='g'){
                    if (*d1<=(max_green)){  //ok for green for this set
                        flag +=1; 
                    }
                    else{
                        flag = 0;   
                        *id = -1;   
                    }

                    if ((*d1)>(*game_max_green)){   // updating max 
                        (*game_max_green) = (*d1);
                    }
                }
                else { // line[i+j] == 'b'
                    if ((*d1)<=(max_blue)){  //ok for blue for this set
                        flag += 1; 
                    }
                    else{
                        flag = 0;   
                        *id = -1;  
                    }

                    if ((*d1)>(*game_max_blue)){   // updating max 
                        (*game_max_blue) = (*d1);
                    }
                }
            }
            j++;

        } // end of set 
        i = j;

        if (flag == 3){
            *id = 0;
        }
	}
               
}