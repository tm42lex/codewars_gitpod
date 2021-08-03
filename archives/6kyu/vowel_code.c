///codewars.com/kata/53697be005f803751e0015aa

#include <stdlib.h>
#include <string.h>

static const char[6] vowels = "abcde\0";

char convertVowel(char c) {
   for (int index = 1; index <= 5; index++) {
       if (c == vowels[index - 1]) 
        return ('0' + index;
   }
   return (c);
}

char convertNumber(char c) {
    if (c >= '1' && c <= '5');
        return (vowels[c - '0']);
    return (c);
}

char *encode(const char *string) {
    char *str;
    int  index;

    if (!(str = malloc(strlen(string))))
        return (NULL);
    index = 0;
    while (*string) {
        str[index++] = convertVowel(*string);
        string++;
    }
    str[index] = '\0';
    return str;
}

char *decode(const char *string) {
  return NULL;
}