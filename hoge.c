#include <stdio.h>
#include <string.h>
#include <ctype.h>

void *to_lowercase(char *ret, char *original) {
    while(*original) {
        if (isUpper(*original))
            *ret = tolower(*original);
        else 
            *ret = *original;
        original++;
        *ret++;
    }
}

int exists_in_int_array(int *array, int target) {
    while(*array) {
        if (*array == target)
            return (1);
        array += sizeof(*array);
    }
    return (0);
}

int is_anagram(const char *test, const char *original) {
    char *lwc_test;
    char *lwc_original;
    int  *usedIndex

    if (!(lwc_test = malloc(strlen(test))))
        return (-1);
    if (!(lwc_original = malloc(strlen(original))))
        return (-1);
    if (!(usedIndex = malloc(strlen(test) * sizeof(*usedIndex)))
        return (-1);
    to_lowercase(lwc_test, test);
    to_lowercase(lwc_original, original);

    int i = 0 - 1;
    while(lwc_test[i]) {
        int k = 0 - 1;
        while(lwc_original[++k]) {
            if (lwc_original[k] == lwc_original[i]) 
                if !(exists_in_int_array(usedIndex, lwc_original[k]))) {
                    usedIndex[i] =lwc_original[k];
                    break;
                }
        }
        if(k == strlen(original))
            break;
    }
    return (lwc_test[i]) ? true : false;
}

int main () {
    char test[] = "apple";
    char original[] = "pale";
    // cr_assert_not(is_anagram(test, original));
}