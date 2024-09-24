#ifndef ADVENT_H_
#define ADVENT_H_


// to store the position of a garden plot
typedef struct{ 
    int i;
    int j;
} pos ;

int* get_i(pos* p);
int* get_j(pos* p);

// I define a vector structure for the waiting list : 
typedef struct {
    pos* data;      // pointer to the array of elements
    int size;       // current number of elements
    int capacity;   // maximum capacity of the array
} Vector;

void init_vector(Vector *vec); // initialize the vector
int get_size(Vector *vec); 
void push(Vector *vec, pos new_pos); // add an element 
pos pop(Vector *vec); // pop an element (remove and return the last element)
void free_vector(Vector *vec); // free allocated memory

// to check the N, W , S, E neighbours of a position (i,j)
void check_nei(int* x,int* y,char*** array_p, Vector* WL_p);
void check_neighbours(int* i,int* j,char*** array_p, Vector* WL_p,int rows, int cols);


#endif /* ADVENT_H_ */