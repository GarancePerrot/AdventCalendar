#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "advent.h"

int main(int argc, char* argv[]){
	FILE *file; 
	//size_t len ;
    char line[10000];
    int ps = 0;
    int sum = 0;

	file = fopen("input.txt", "r"); 
	if (file == NULL){                     //error handling
		printf("Error: file not found\n");
		return 1;
	}

	while (fgets(line, sizeof(line), file)){  //reads file line by line
		//printf("Reading line : %s\n", line);
		//len = strlen(line);
		
        char* token = strtok(line, ","); // parse line with separator ','
        while (token != NULL){
            //printf("%s\n", token);
            get_hash(token, &ps);
            sum += ps;
            token = strtok(NULL, ",");
        }

	}
	
    printf("Final reslut is %d\n", sum);
	fclose(file);

    // debug, checking hash function
    // int ps;
    // get_hash("bzk-", &ps);
    // printf("result %d\n", ps);
	return 0; 
}