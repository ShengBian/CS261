/* CS261- Assignment 1 - Q.5*/
/* Name: Sheng Bian
 * Date: January 20, 2018
 * Solution description: This program defines a function called sticky takes a single
 * word and modify the word to appear with "sticky caps".
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
    if((ch >= 97) && (ch <= 122)){
        return ch-'a'+'A';
    }
    return ch;
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){

    if((ch >= 65) && (ch <= 90)){
        return ch-'A'+'a';
    }
    return ch;
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int i = 0;
    while (word[i] != '\0'){
        if(i % 2 == 0){
            word[i] = toUpperCase(word[i]);
        }
        else{
            word[i] = toLowerCase(word[i]);
        }
        i++;
    }
}

int main(){
    char word[256];
    printf("Please enter the word ");
    /*Read word from the keyboard using scanf*/
    scanf("%s", word);
    /*Call sticky*/
    sticky(word);
    /*Print the new word*/
    printf("%s\n", word);
    return 0;
}
