#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    bool a, e, i, o, u;
    int consonants;
    int (*check)(struct CharTracker* self, int k);
    void (*read)(struct CharTracker *self, char c);
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
    CharTracker t = {false, false, false, false, false, 0, charTrackerCheck, charTrackerReadLetter};
    return t;
}

bool validSubstringExists(char* word, int k, int index, int arr_length) 
{
    CharTracker tracker = createCharTracker();

    while(index < arr_length)
    {
        tracker.read(&tracker, word[index]);

        int check_val = tracker.check(&tracker, k);

        if(check_val == 1) {
            return true;
        } else if (check_val == 2) {
            return false;
        }

        index++;
    }

    return false;
}

long long countOfSubstrings(char* word, int k) 
{
    int arr_length = strlen(word);
    int substr_count = 0;

    for (int i = 0; i < arr_length; i++) {
        if(validSubstringExists(&word, k, i, arr_length)) {
            substr_count++;
        }
    }
}

int main() {
    char word[6] = "aeioqq";
    int k = 1;

    long count = countOfSubstrings(&word, k);

    printf("Example 1 answer: %d", count);
    
    char word[5] = "aeiou";
    int k = 0;

    long count = countOfSubstrings(&word, k);

    printf("Example 2 answer: %d", count);
    
    char word[14] = "ieaouqqieaouqq";
    int k = 1;

    long count = countOfSubstrings(&word, k);

    printf("Example 3 answer: %d", count);

    return 0;
}