#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char *word;

    while (!feof(file)) {
        word = nextWord(file);
        if(word){
            hashMapPut(map, word, 1);
        }
    }
    free(word);
}

/**
 * Get the Levenshtein distance for two strings. The code is based on wiki page
 * provided by instructor and reference from https://rosettacode.org/wiki/Levenshtein_distance#C
 * @param firstString
 * @param secondString
 */
int getLevenshteinDistance(char *firstString, char *secondString)
{
    int ls = strlen(firstString), lt = strlen(secondString);
    int d[ls + 1][lt + 1];

    for (int i = 0; i <= ls; i++){
        for (int j = 0; j <= lt; j++){
            d[i][j] = -1;
        }
    }

    int dist(int i, int j) {
        if (d[i][j] >= 0){
            return d[i][j];
        }
        int x;
        if (i == ls){
            x = lt - j;
        }
        else if (j == lt){
            x = ls - i;
        }
        else if (firstString[i] == secondString[j]){
            x = dist(i + 1, j + 1);
        }

        else {
            x = dist(i + 1, j + 1);
            int y;
            if ((y = dist(i, j + 1)) < x){
                x = y;
            }
            if ((y = dist(i + 1, j)) < x){
                x = y;
            }
            x++;
        }
        return d[i][j] = x;
    }
    return dist(0, 0);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
        //convert string to lower case
        for (int i = 0; inputBuffer[i] ; i++) {
            inputBuffer[i] = tolower(inputBuffer[i]);
        }

        int distance;
        char *input = &inputBuffer[0];

        //Computing their Levenshtein distance. Store that distance as the value for each key in the table.
        int minDistance = 1000000;
        for (int j = 0; j < map->capacity; j++) {
            HashLink* link = map->table[j];
            if (link != NULL)
            {
                while (link != NULL)
                {
                    distance = getLevenshteinDistance(input, link->key);
                    hashMapPut(map, link->key, distance);
                    if(distance < minDistance){
                        minDistance = distance;
                    }
                    link = link->next;
                }
            }
        }

        if(hashMapContainsKey(map, inputBuffer)){
            printf("%s spelled correctly\n", inputBuffer);
        }
        else {
            int k = 0;
            while(k < 5){
                for (int i = 0; i < map->capacity; i++)
                {
                    HashLink* link = map->table[i];
                    if (link != NULL)
                    {
                        while (link != NULL)
                        {
                            if(link->value == minDistance){
                                printf("Did you mean %s?\n", link->key);
                                k++;
                            }
                            link = link->next;
                            if(k == 5){
                                link = NULL;
                                i = map->capacity;
                                break;
                            }
                        }
                    }
                }
                minDistance++;
            }
        }
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
    }
    hashMapDelete(map);
    return 0;
}