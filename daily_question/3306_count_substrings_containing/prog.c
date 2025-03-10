#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    bool a, e, i, o, u;
    int consonants;
    int (*check)(struct CharTracker* self, int k);
} CharTracker;

// Returns 0 for substring not found yet, 1 for substring found, 2 for subtring cannot be found, k is larger than acceptable consonants
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

void initializeCharTracker(CharTracker* t)
{
    t->a = t->e = t->i = t->o = t->u = false;
    t->consonants = 0;
    t->check = charTrackerCheck;
}


bool substringCheck(char* word, int k, int index, int arr_length) 
{
    CharTracker tracker = {false, false, false, false, false, 0, charTrackerCheck};




    return 0;
}

long long countOfSubstrings(char* word, int k) 
{
    int arr_length = strlen(word);
    int substr_count = 0;

    for (int i = 0; i < arr_length; i++) {

    }
}

int main() {

    return 0;
}