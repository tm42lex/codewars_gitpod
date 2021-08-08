#include <stdlib.h> /// malloc
#include <string.h> /// strlen

#include <stdio.h>

int  is_numchar(char c) {
    return (c >= '0' && c <= '9');
}

int numchar_to_int(char c) {
    return (c - '0');
}

void convert_to_int_array(int *array, char *strg, int records, int index) {
    int sec    = 0;
    int digits = 0;
    
    if (index == records)
        return ;
    while (digits < 6 && *strg) {
        while (*strg && !is_numchar(*strg))
            strg++;
        if (digits %2 == 0)
            sec = sec * 60 + numchar_to_int(*strg) * 10;
        else
            sec += numchar_to_int(*strg);
        strg++;
        digits++;
    }
    array[index] = sec;
    return convert_to_int_array(array, strg, records, index + 1);
}

char* stat(char* strg) {
    int *array;
    int count;
    int index;
    int range;
    int average;
    int mean_l;
    int mean_r;
    
    count = strlen(strg) + 2; // for missing ", " at the end
    if (count < 2 || count %10 != 0) 
        return "";
    count /= 10;
    if (!(array = (int *)malloc(count  * sizeof(*array))))
        return (NULL);
    convert_to_int_array(array, strg, count, 0);
    mean_l = (count % 2 == 0) ? count / 2 - 1 : (count - 1) / 2 - 1;
    mean_r = (count % 2 == 0) ? count / 2 - 1 : (count + 1) / 2 - 1;
    range  = array[count - 1] - array[0];

    printf("%d\n", count);
    printf("%d\n", mean_l);
    printf("%d\n", mean_r);
    printf("%d\n", range);

    return (NULL);
}

int main() {
    char* l = "02|15|59, 02|47|16, 02|17|20, 02|32|34, 02|17|17, 02|22|00, 02|31|41";
    stat(l);
    return (0);
}