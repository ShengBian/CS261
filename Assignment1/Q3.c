/* CS261- Assignment 1 - Q.3*/
/* Name: Sheng Bian
 * Date: January 20, 2018
 * Solution description: This program defines a sort function to sort a given array of n integers
 * in ascending order.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(number[i] > number[j]){
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int* arr = (int *)malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }
    /*Print the contents of the array.*/
    printf("The original contents of array: \n");
    for (int j = 0; j < n; j++) {
        printf("%d\n", arr[j]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(arr, n);
    /*Print the contents of the array.*/
    printf("The contents of array after sorting: \n");
    for (int k = 0; k < n; k++) {
        printf("%d\n", arr[k]);
    }
    return 0;
}
