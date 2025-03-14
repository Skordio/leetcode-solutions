#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// CharTracker ----------------------------------------------------------------

typedef struct {
    int a, e, i, o, u, consonants;
} CharTracker;


bool enoughVowels(CharTracker* t) {
    return t->a > 0 && t->e > 0 && t->i > 0 && t->o > 0 && t->u > 0;
}

// Returns 0 for substring not found yet, 1 for substring found, 2 if subtring cannot be found
int trackerCheck(CharTracker* t, int k)
{
    if (t->consonants < k) {
        return 0;
    } else if (t->consonants > k) {
        return 2;
    }

    if (enoughVowels(t)) {
        return 1;
    } else {
        return 0;
    }
}

void considerLetter(CharTracker* t, char c, int add)
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

// SlidingWindow --------------------------------------------------------------

typedef struct {
    int start_index, end_index;
} SlidingWindow;

void growWindowEnd(SlidingWindow* w, CharTracker* t, const char* word) 
{
    considerLetter(t, word[w->end_index], 1);
    w->end_index++;
}

void growWindowStart(SlidingWindow* w, CharTracker* t, const char* word) 
{
    w->start_index--;
    considerLetter(t, word[w->start_index], 1);
}

void shrinkWindowStart(SlidingWindow* w, CharTracker* t, const char* word) 
{
    considerLetter(t, word[w->start_index], -1);
    w->start_index++;
}

void shrinkWindowEnd(SlidingWindow* w, CharTracker* t, const char* word) 
{
    w->end_index--;
    considerLetter(t, word[w->end_index], -1);
}

void slideWindow(SlidingWindow* w, CharTracker* t, const char* word) 
{
    shrinkWindowStart(w, t, word);
    growWindowEnd(w, t, word);
}

SlidingWindow createSlidingWindow() {
    SlidingWindow w = {0, 1};
    return w;
}

// void slice(const char* str, char* result, size_t start, size_t end) {
//     strncpy(result, str + start, end - start);
// }

// Functions -------------------------------------------------------------------

void shrinkStartAndCheckSubstrs(SlidingWindow* w, CharTracker* t, const char* word, int k, long long* substr_count)
{
    int shrinks = 0;

    while (enoughVowels(t))
    {
        shrinkWindowStart(w, t, word);
        shrinks++;

        int check_val = trackerCheck(t, k);

        if (check_val == 1) {
            *substr_count += 1;
        } else if (t->consonants < k) {
            break;
        }

    }
    
    for (int i = 0; i < shrinks; i++) {
        growWindowStart(w, t, word);
    }
}

long long countOfSubstrings(char* word, int k) 
{
    int arr_length = strlen(word);
    long long substr_count = 0;
    
    CharTracker tracker = createCharTracker();
    SlidingWindow window = createSlidingWindow();

    considerLetter(&tracker, word[0], 1);

    // char substring[50] = "";

    while(window.start_index < arr_length)
    {
        int check_val = trackerCheck(&tracker, k);
    
        // slice(word, substring, window.start_index, window.end_index);
        // printf("Checking substring: %s\n", substring);

        if (check_val == 1) {
            substr_count++;
            // slice(word, substring, start_index, end_index);
            // printf("Found good substring: %s\n", substring);
        }
    
        if (check_val == 2)
        {
            if (window.start_index == window.end_index)
            {
                slideWindow(&window, &tracker, word);
            }
            else {
                shrinkWindowStart(&window, &tracker, word);
            }
        } 
        else if (window.end_index == arr_length) {
            shrinkWindowStart(&window, &tracker, word);
        }
        else 
        {
            shrinkStartAndCheckSubstrs(&window, &tracker, word, k, &substr_count);
            growWindowEnd(&window, &tracker, word);
        }
    }

    return substr_count;
}
