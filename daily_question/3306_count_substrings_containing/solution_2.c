// Incorrect Answer -----------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int a, e, i, o, u, consonants;
} CharTracker;

// Returns 0 for substring not found yet, 1 for substring found, 2 if subtring cannot be found
int charTrackerCheck(CharTracker* t, int k)
{
    if (t->consonants < k) {
        return 0;
    } else if (t->consonants > k) {
        return 2;
    }

    if (t->a > 0 && t->e > 0 && t->i > 0 && t->o > 0 && t->u > 0) {
        return 1;
    } else {
        return 0;
    }
}

void charTrackerCheckLetter(CharTracker* t, char c, int add)
{
    switch(c) 
    {
        case 'a':
            t->a += add;
            return;
        case 'e':
            t->e += add;
            return;
        case 'i':
            t->i += add;
            return;
        case 'o':
            t->o += add;
            return;
        case 'u':
            t->u += add;
            return;
        default:
            t->consonants += add;
            return;
    }
}

CharTracker createCharTracker()
{
    CharTracker t = {0, 0, 0, 0, 0, 0};
    return t;
}

long long countOfSubstrings(char* word, int k) 
{
    int arr_length = strlen(word);
    long long substr_count = 0;
    
    CharTracker tracker = createCharTracker();

    int start_index = 0;
    int end_index = 1;
    int consider_index = 0;

    char substring[50] = "";

    while(start_index < arr_length && end_index <= arr_length)
    {
        if (consider_index >= arr_length) { break; }

        charTrackerCheckLetter(&tracker, word[consider_index], consider_index == (end_index-1) ? 1 : -1);

        int check_val = charTrackerCheck(&tracker, k);

        if (check_val == 1) {
            substr_count++;
        }

        if (check_val == 2 || end_index == arr_length)
        {
            consider_index = start_index;
            start_index++;
        } 
        else 
        {
            end_index++;
            consider_index = (end_index-1);
        }
    }

    return substr_count;
}
