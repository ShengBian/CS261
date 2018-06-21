/*	stack.c: Stack application. */
/*  Name: Sheng Bian
 *  Date: January 29, 2018
 *  Solution description: This program defines a function to check whether an expression
 *  has balanced paratheses, braces, and brackets or not.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	char c;
	DynArr *stack = newDynArr(10);
	do {
		c = nextChar(s);
		if(c == '(' || c == '[' || c == '{')
		{
			pushDynArr(stack, c);
		}
		else if((c == ')' && topDynArr(stack) == '(') ||
				(c == '}' && topDynArr(stack) == '{') ||
				(c == ']' && topDynArr(stack) == '['))
		{
			popDynArr(stack);
		}
	} while (c != '\0');

	if(!isEmptyDynArr(stack))
	{
		deleteDynArr(stack);
		return 0;
	}

	deleteDynArr(stack);
	return 1;


}

int main(int argc, char* argv[]){
	
	char* s="[(((x+y)+Z))]";
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

