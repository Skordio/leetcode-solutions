// Answer ---------------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "solution.h"

typedef struct {
    bool a, e, i, o, u;
    int consonants;
} CharTracker;

// Returns 0 for substring not found yet, 1 for substring found, 2 if subtring cannot be found
int charTrackerCheck(CharTracker* t, int k)
{
    if(t->consonants < k) {
        return 0;
    } else if(t->consonants > k) {
        return 2;
    }

    if(t->a && t->e && t->i && t->o && t->u) {
        return 1;
    }

    return 0;
}

void charTrackerReadLetter(CharTracker* t, char c)
{
    switch(c) 
    {
        case 'a':
            t->a = true;
            return;
        case 'e':
            t->e = true;
            return;
        case 'i':
            t->i = true;
            return;
        case 'o':
            t->o = true;
            return;
        case 'u':
            t->u = true;
            return;
        default:
            break;
    }

    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) 
    {
        t->consonants++;
    }
}

CharTracker createCharTracker()
{
    CharTracker t = {false, false, false, false, false, 0};
    return t;
}

void checkForValidSubstrings(char* word, int k, int index, int arr_length, int* substr_count) 
{
    CharTracker tracker = createCharTracker();

    while(index < arr_length)
    {
        charTrackerReadLetter(&tracker, word[index]);

        int check_val = charTrackerCheck(&tracker, k);

        if(check_val == 1) {
            *substr_count = *substr_count+1;
        } else if (check_val == 2) {
            return;
        }

        index++;
    }

    return;
}

long long countOfSubstrings(char* word, int k) 
{
    int arr_length = strlen(word);
    int substr_count = 0;

    for (int i = 0; i < arr_length; i++) {
        checkForValidSubstrings(word, k, i, arr_length, &substr_count);
    }

    return substr_count;
}
