/* CS261- Assignment 1 - Q. 0*/
/* Name: Sheng Bian
 * Date: January 21, 2018
 * Solution description: This program defines a function that takes a pointer to an
 * integer as argument. It prints the value of the integer pointed to by that pointer,
 * the address pointed to by pointer, and the address of pointer itself
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value pointed to by iptr is %d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("The address pointed to by iptr is %p\n", iptr);
     /*Print the address of iptr itself*/
     printf("The address of iptr itself is %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 100;
    /*print the address of x*/
    printf("The address of x is %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of x is %d\n", x);

    return 0;
}
