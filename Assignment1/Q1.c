/* CS261- Assignment 1 - Q.1*/
/* Name: Sheng Bian
 * Date: January 20, 2018
 * Solution description: This program defines a struct called student and creates different functions
 * to allocate memory for ten students, generate random and unique ID and scores for ten students,
 * output information about ten students, compute and print the minimum, maximum and average scores of
 * the ten students and deallocate memory.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* stud = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return stud;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
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
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < 10; i++) {
        printf("ID%d %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int max = 0;
     int min = 100;
     float total = 0;

    for (int i = 0; i < 10; i++) {
        if(students[i].score > max) {
            max = students[i].score;
        }
        if(students[i].score < min) {
            min = students[i].score;
        }
        total += students[i].score;
    }

    printf("The maximum score of the ten students is: %d\n", max);
    printf("The minimum score of the ten students is: %d\n", min);
    printf("The average score of the ten students is: %f\n", total/10);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
