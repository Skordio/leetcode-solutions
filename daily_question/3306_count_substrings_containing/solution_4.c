#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// CharTracker ----------------------------------------------------------------

typedef struct {
    int a, e, i, o, u, consonants, start_index, end_index;
} CharTrackerWindow;

bool enoughVowels(CharTrackerWindow* t) {
    return t->a > 0 && t->e > 0 && t->i > 0 && t->o > 0 && t->u > 0;
}

bool isValid(CharTrackerWindow* t, int k) {
    return t->consonants == k && enoughVowels(t);
}

void considerLetter(CharTrackerWindow* t, char c, int add)
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

void extendWindowEnd(CharTrackerWindow* t, const char* word) 
{
    considerLetter(t, word[t->end_index], 1);
    t->end_index++;
}

void extendWindowStart(CharTrackerWindow* t, const char* word) 
{
    t->start_index--;
    considerLetter(t, word[t->start_index], 1);
}

void shrinkWindowStart(CharTrackerWindow* t, const char* word) 
{
    considerLetter(t, word[t->start_index], -1);
    t->start_index++;
}

void shrinkWindowEnd(CharTrackerWindow* t, const char* word) 
{
    t->end_index--;
    considerLetter(t, word[t->end_index], -1);
}

void slideWindow(CharTrackerWindow* t, const char* word) 
{
    shrinkWindowStart(t, word);
    extendWindowEnd(t, word);
}

CharTrackerWindow createCharTrackerWindow()
{
    CharTrackerWindow t = {0, 0, 0, 0, 0, 0, 0, 1};
    return t;
}

void shrinkStartAndCheckSubstrs(CharTrackerWindow* t, const char* word, int k, long long* substr_count)
{
    int shrinks = 0;

    while (enoughVowels(t))
    {
        shrinkWindowStart(t, word);
        shrinks++;

        int check_val = trackerCheck(t, k);

        if (check_val == 1) {
            *substr_count += 1;
        } else if (t->consonants < k) {
            break;
        }

    }
    
    for (int i = 0; i < shrinks; i++) {
        growWindowStart(t, word);
    }
}

// void slice(const char* str, char* result, size_t start, size_t end) {
//     strncpy(result, str + start, end - start);
// }

long long countOfSubstrings(char* word, int k) 
{
    int arr_length = strlen(word);
    long long substr_count = 0;
    int last_move = 0; // 0 for extend end, 1 for shrink start or slide

    CharTrackerWindow tracker = createCharTrackerWindow();

    considerLetter(&tracker, word[0], 1);

    while (tracker.start_index < arr_length) 
    {
        // if we have found a valid substring,
        if (isValid(&tracker, k)) {
            if (last_move == 0) {
                // shrink start until it isn't valid anymore
                while (isValid(&tracker, k)) {
                    shrinkWindowStart(&tracker, word);
                }
                // then grow start by one 
                extendWindowStart(&tracker, word);
            }
            else {
                // and shrink end until it isn't valid anymore
                while (isValid(&tracker, k)) {
                    shrinkWindowEnd(&tracker, word);
                }
                // then grow end by one so we have a valid, minimum length substring
                extendWindowEnd(&tracker, word);
            }

            substr_count++;

            // now use new copy of tracker
            CharTrackerWindow copy;

            memcpy(&copy, &tracker, sizeof(CharTrackerWindow));

            // to find valid strings to the left
            while (copy.start_index > 0)
            {
                extendWindowStart(&copy, word);
                if (isValid(&copy, k)) {
                    substr_count++;
                } else {
                    break;
                }
            }

            memcpy(&copy, &tracker, sizeof(CharTrackerWindow));

            // and to the right
            while (copy.end_index <= arr_length) {
                extendWindowEnd(&copy, word);
                if (isValid(&copy, k)) {
                    substr_count++;
                } else {
                    break;
                }
            }

            // then finally shrink the window start by one so it isn't valid anymore and we go on to find the next minimum length substr
            shrinkWindowStart(&tracker, word);
            last_move = 1;
        }
        else {
            // If the substr isn't valid first begin by extending the end until either it is valid, or we have too many consonants

            // if too many consonants, begin shrinking the start until either it is valid, we stop having too many consonants, or the window is a length of 1

            // if it is a length of 1 and we still have too many consonants, slide the window forward until there aren't too many consonants

            if (tracker.consonants > k) {
                
            } else {
                if (tracker.end_index < arr_length) {
                    extendWindowEnd(&tracker, word);
                    last_move = 0;
                } else {
                    shrinkWindowStart(&tracker, word);
                    last_move = 1;
                }
            }
        }
    }

    return substr_count;
}
