#include <stdio.h>
#include <windows.h>

/* Declaring an global variable */
char name[20] = "Ronaldo";


int main (){


    /* 2. Printing name and your memory adress */
    printf("Name: %s, Memory adress: %p\n", name, &name);

    return 0;

}