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

void growWindowEnd(SlidingWindow* w, CharTracker* t, const char* word) {
    considerLetter(t, word[w->end_index], 1);
    w->end_index++;
}

void growWindowStart(SlidingWindow* w, CharTracker* t, const char* word) {
    w->start_index--;
    considerLetter(t, word[w->start_index], 1);
}

void shrinkWindowStart(SlidingWindow* w, CharTracker* t, const char* word) {
    considerLetter(t, word[w->start_index], -1);
    w->start_index++;
}

void shrinkWindowEnd(SlidingWindow* w, CharTracker* t, const char* word) {
    w->end_index--;
    considerLetter(t, word[w->end_index], -1);
}

void slideWindow(SlidingWindow* w, CharTracker* t, const char* word) {
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

// Function -------------------------------------------------------------------

long long countOfSubstrings(char* word, int k) 
{
    int arr_length = strlen(word);
    long long substr_count = 0;
    
    CharTracker track = createCharTracker();
    SlidingWindow window = createSlidingWindow();

    considerLetter(&track, word[0], 1);

    // char substring[50] = "";

    while(window.start_index < arr_length)
    {
        int check_val = trackerCheck(&track, k);
    
        // slice(word, substring, window.start_index, window.end_index);
        // printf("Checking substring: %s\n", substring);

        if (check_val == 1) {
            substr_count++;
            // slice(word, substring, start_index, end_index);
            // printf("Found good substring: %s\n", substring);
        }
    
        if (check_val == 2)
        {
            // If we have too many consonants, but enough vowels,
            if (enoughVowels(&track)) {

                // move end of window back by one
                shrinkWindowEnd(&window, &track, word);

                // move start up by one to avoid counting strings we already have
                shrinkWindowStart(&window, &track, word);

                // and shrink start of window while checking for good substrings
                while (enoughVowels(&track))
                {
                    check_val = trackerCheck(&track, k);

                    if (check_val == 1) {
                        substr_count++;
                    }

                    shrinkWindowStart(&window, &track, word);

                    if(!enoughVowels(&track)) {
                        growWindowStart(&window, &track, word);
                        break;
                    }
                }

                // Add back the rightmost space because now we have explored all possibilities without including it
                growWindowEnd(&window, &track, word);
            } 
            else if (window.start_index == window.end_index)
            {
                slideWindow(&window, &track, word);
            }
            else {
                shrinkWindowStart(&window, &track, word);
            }
        } 
        else if (window.end_index == arr_length) {
            shrinkWindowStart(&window, &track, word);
        }
        else 
        {
            growWindowEnd(&window, &track, word);
        }
    }

    return substr_count;
}
