#ifndef ADVENT_H_
#define ADVENT_H_

// I create my dicitonary of key-value pairs for letter digits :

struct letter_digit {
    char* key;
    int value;
};

extern struct letter_digit digits[];

extern struct letter_digit reversed_digits[];

void get_num(char* line, char* rev, int* f, int* l, int* num);


#endif /* ADVENT_H_ */