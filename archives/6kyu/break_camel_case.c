#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isUpperCase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int countLen(const char *str) {
    int index          = 0;

    while(*str) {
        if (isUpperCase(*str) && index != 0)
            index++;
        index++;
        str++;
    }
    return index;
}

char* solution(const char *camelCase) {
    char    *ret;
    int     len;
    int     index;

    if (camelCase == NULL)
      return (NULL);
    len = countLen(camelCase);
    if(!(ret = (char *)malloc(len * sizeof(*ret))))
        return (NULL);
    index = 0;
    while(index < len) {
        if (isUpperCase(*camelCase) && index != 0) 
           ret[index++] = ' '; 
        ret[index++] = *(camelCase++);
    }
    ret[index] = '\0';
    return ret;
}

int main() {
    const char *s1 = "camelCase";
    const char *s2 = "camelcase";
    const char *s3 = "theLongestPalindrome";

    printf("%s\n", solution(s1));
    printf("%s\n", solution(s2));
    printf("%s\n", solution(s3));
    return (0);
}