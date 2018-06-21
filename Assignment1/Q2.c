/* CS261- Assignment 1 - Q.2*/
/* Name: Sheng Bian
 * Date: January 20, 2018
 * Solution description: This program defines a foo function to twice the original value,
 * half the original value. It prints out three numbers and then call the foo function.
 * At last, it prints out three numbers again.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5,
        y = 6,
        z = 7;
    /*Print the values of x, y and z*/
    printf("x: %d y: %d z: %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int value = foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("The value returned by foo is %d\n", value);
    /*Print the values of x, y and z again*/
    printf("x: %d y: %d z: %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/
    /*Yes, the return value is different than the value of z. z is passed by value into the foo function rather than address,
     * so z remains unchanged. */
    return 0;
}
    
    
