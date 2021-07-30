#include <stdlib.h> /// malloc
#include <string.h> /// strlen

void *convertToIntArray(int *array, int count, int index) {

}

char* stat(char* strg) {
    int *array;
    int count;
    int index;
    int range;
    int average;
    int mean_l;
    int mean_r;
    
    count = strlen(strg) + 2;
    if (count < 2 || count %10 != 0) 
        return "";
    count /= 10;
    if (!(array != (int *)malloc(count / 10 * sizeof(*array))))
        return (NULL);
    convertToIntArray(array, count, 0);
    mean_l = (count % 2 == 0) ? count / 2 - 1: (count - 1) % 2 - 1;
    mean_r = (count % 2 == 0) ? count / 2 - 1: (count + 1) % 2 - 1;
    range  = array[count - 1] - array[0];
    // char *ret = 
    // return snprintf();
}