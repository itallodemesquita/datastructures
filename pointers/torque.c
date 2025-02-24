#include <stdio.h>

int main () {
    
    float torque[10] = {2.5, 8.1, 3.4, 9.2, 5.7, 9.6, 6.3, 8.0, 5.4, 4.9};
    float * ptr1 = &torque[0];
    float * ptr2 = &torque[9];

    printf("Primeiro: %.1f \nÚltimo: %.1f", *ptr1, *ptr2);

    return 0;
}
