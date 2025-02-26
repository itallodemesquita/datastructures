#include <stdio.h>
#include <windows.h>

/* Defining a structure */

typedef struct {

    char name[20];
    float salary;
    unsigned goals;

} player;

int main (){

    player p1 = {"Ronaldo", 1000000, 920};

    player p4 = {"Memphis", 1000000, 300};
    player p5 = {"Yuri", 1000000, 130};

    player *ptr = &p4;
    player *ptr2 = &p5;

    printf("Name: %s, Salary: %.2f, Goals: %d, \n", p1.name, p1.salary, p1.goals);
    printf("--------------------\n\n");
    Sleep(2000);

    printf("Name: %s, Salary: %.2f, Goals: %d, \n", ptr->name, ptr->salary, ptr->goals);
    printf("--------------------\n\n");
    Sleep(2000);

    printf("Name: %s, Salary: %.2f, Goals: %d, \n", ptr2->name, ptr2->salary, ptr2->goals);
    printf("--------------------\n\n");
    Sleep(2000);

    return 0;

}