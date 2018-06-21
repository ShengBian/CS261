/* CS261- Assignment 1 - Q.4*/
/* Name: Sheng Bian
 * Date: January 20, 2018
 * Solution description: This program defines a sort function to sort
 * an array of n students based on their scores in ascending order
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
	struct student temp;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if(students[i].score > students[j].score){
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
	struct student* students = malloc(15 * sizeof(struct student));
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	for (int i = 0; i < 10; i++) {
		students[i].score = (rand() % 101);
	}
	/*The following code I get help from the following website, answer by mob
	reference:https://stackoverflow.com/questions/1608181/unique-random-numbers-in-an-integer-array-in-the-c-programming-language*/
	int list[10];
	for(int i = 0; i < 10; i++) {
		list[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		int j = i + rand()%(10 - i);
		int temp = list[i];
		list[i] = list[j];
		list[j] = temp;
		students[i].id = list[i] + 1;
	}
    /*Print the contents of the array of n students.*/
	printf("Before sorting: \n");
	for (int i = 0; i < 10; i++) {
		printf("ID%d %d\n", students[i].id, students[i].score);
	}
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    /*Print the contents of the array of n students.*/
	printf("After sorting: \n");
	for (int i = 0; i < 10; i++) {
		printf("ID%d %d\n", students[i].id, students[i].score);
	}
    return 0;
}
