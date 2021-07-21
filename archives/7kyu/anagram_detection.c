#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_lowercase(char *ret, const char *original) {
    while(*original) {
        if (isupper(*original))
            *ret = tolower(*original);
        else 
            *ret = *original;
        original++;
        ret++;
    }
    *ret = '\0';
}

int exists_in_int_array(int *array, int target) {
    while(*array != -1) {
        if (*array == target)
            return (1);
        array++;
    }
    return (0);
}


void fill_int_array(int *array, int length, int target) {
    while(length--) {
        *array = target;
         array++;
    }
}

int is_anagram(const char *test, const char *original) {
    char *lwc_test;
    char *lwc_original;
    int  *usedIndex;
    int  test_len     = strlen(test);
    int  original_len = strlen(original);

    if (!(lwc_test = malloc(test_len + 1)))
        return (-1);
    if (!(lwc_original = malloc(original_len + 1)))
        return (-1);
    if (!(usedIndex = malloc(test_len * sizeof(*usedIndex))))
        return (-1);
    to_lowercase(lwc_test, test);
    to_lowercase(lwc_original, original);
    fill_int_array(usedIndex, test_len, -1);

    int i = 0 ;
    while(lwc_test[i]) {
        int k = 0 - 1;
        while(lwc_original[++k]) {
            if (lwc_original[k] == lwc_test[i]) 
                if (!(exists_in_int_array(usedIndex, k))) {
                    // printf("%d", k);
                    usedIndex[i++] = k;
                    break;
                }
        }
        if(k == original_len)
            break;
    }
    return (lwc_test[i]) ? 0 : 1;
}

int main () {
    char test[] = "apple";
    char original[] = "lepa";
    printf("%d\n", is_anagram(test, original));
}