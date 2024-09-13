#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "advent.h"

int main(int argc, char* argv[]){
	FILE *file; 
	char line[256];                         //store each line
	char rev[256];                          // to reverse each line
	size_t len ;
	int i;
	int f, l, num;                         // for first & last digit of each line and the number formed
	int sum = 0;                           // for global sum

	file = fopen("input.txt", "r"); 
	if (file == NULL){                     //error handling
		printf("Error: file not found\n");
		return 1;
	}

	while (fgets(line, sizeof(line), file)){  //reads file line by line
		//printf("Reading line : %s\n", line);
		len = strlen(line);
		for (i = 0; i < len; i++) {
			rev[i] = line[len-1-i];
		}
		rev[len] = '\0';

		get_num(line, rev, &f, &l, &num);        // get number for each line
		sum += num;                        // add to global sum
		//printf("Current sum : %d\n", sum);
	}
	printf("Final result is %d\n", sum);
	fclose(file);
	return 0; 
}
