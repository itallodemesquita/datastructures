/* Laboratory 2 - Data Structures and Algorithms*/
/* Ítallo de Mesquita */
/* Prof. George Felipe */

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


/* Making a struct */
typedef struct {
    char type[20];
    float weight;
    int height;
} fish;


void transition() { /* Function to make a transition between the prints */
    printf("---------------\n\n");
    Sleep(2000);
}

/* 2) a. Function to print fish informations with 'fish' as parameter */
void print_fish(fish fish) {
    printf("Imprimindo peixe: \n");
    printf("Type: %s, Weight: %.2f, Height: %d\n", fish.type, fish.weight, fish.height);    
}

/* 2) b. Function to print fish informations with a pointer as parameter */
void print_fish_point(fish *fish) {
    printf("Imprimindo peixe com ponteiro: \n");
    printf("Type: %s, Weight: %.2f, Height: %d\n", fish->type, fish->weight, fish->height);    
}


int main (){

    printf("\nLaboratory 2 - Data Structures and Algorithms\n\n");

    fish fish1 = {"Tilapia", 0.5, 10};

    /* Making a pointer to fish1 */
    fish *pointer = &fish1;


    /* Question 2) a. Printing the fish informations */
    print_fish(fish1);
    transition();

    /* Question 2) b. Printing the fish informations with pointer */
    print_fish_point(pointer);
    transition();

    return 0;

}