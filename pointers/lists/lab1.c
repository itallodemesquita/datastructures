#include <stdio.h>
#include <windows.h>

/* Declaring the globals variables */
char name[20] = "Ronaldo";
int x = 68, y;
int *point = &x;


void transition() { /* Function to make a transition between the prints */
    printf("---------------\n\n");
    Sleep(2000);
}



int main (){

    y = *point + 200;


    /* 2. Printing name and your memory adress */
    printf("Name: %s, Memory adress: %p\n", name, &name); /* Print the value and the memory adress of 'name'*/
    transition();

    /* Referencing 'name' with pointer 'indica' */
    char *indica = name;
    printf("Name: %s\n", indica); /* Print the value of 'name' using the pointer */
    transition();
    

    /* 5. Printing the variables x, y and point */
    printf("x: %d\n", x); /* Print the value of 'x' */
    printf("y: %d\n", y); /* Print the value of 'y' */
    printf("point: %p\n", point); /* Print the memory address of 'point' */
    transition();
    

    /* 6. Reading the value of 'x'*/
    int *px = &x;
    printf("Write a new valeu to x: ");
    scanf("%d", px); /* Read the value of 'x' */
    printf("x: %d\n", *px); /* Print the value of 'x' */

    return 0;

}