#include <stdlib.h> /// malloc, free
#include <string.h> /// strlen

#include <stdio.h>

char num_padleft_zero(int num, int is_last_digit) {
    if (!is_last_digit && num < 10)
        return ('0');
    int base = (is_last_digit) ? num : num / 10;
    return ('0' + base % 10);
}

char *sec_to_HMS(int s) {
    int h;
    int m;
    char *ret;

    if (!(ret = malloc(6 + 1)))
        return (NULL);
    h = s / (60 * 60);
    s -= 60 * 60 * h ;
    m = s / 60;
    s -= 60 * m;
    
    int i = 0;
    int num = h;
    while (i < 6) {
        if (i == 2)
            num = m;
        if (i == 4)
            num = s;
        ret[i] = num_padleft_zero(num, i % 2);
        i++;
    }
}

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
    sec_to_HMS(sec);
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
    free(array);
    return (NULL);
}

int main() {
    char* l = "02|15|59, 02|47|16, 02|17|20, 02|32|34, 02|17|17, 02|22|00, 02|31|41";
    stat(l);
    return (0);
}