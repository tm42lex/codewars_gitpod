//https://www.codewars.com/kata/546f922b54af40e1e90001da/train/c

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int alphabet_to_number(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    else 
        return -1;
}

char *number_to_alphabet_sd(int c) {
    char *ret = calloc((c > 10) ? 3 : 2, 1);
    if (c < 10) {
        sprintf(ret, "%c%c", c + '0', '\0');
        return ret;
    }
    else {
        char *singleDigit = number_to_alphabet_sd(c%10);
        char secondDigit  = (c >= 20) ? '2' : '1';
        sprintf(ret, "%c%s%c", secondDigit, singleDigit, '\0');
        free(singleDigit);
        return ret;
    }
}

char *alphabet_position(char *text) {
  char *ans = calloc(INT_MAX, 1);
  while(*text) {
    int    num  = alphabet_to_number(*text);
    if (num != -1) {
        char *digit = number_to_alphabet_sd(num);
        sprintf(ans, "%s%s", ans, digit);
        free(digit);
    }
    text++;
    if (*text && num != -1)
        sprintf(ans, "%s%c", ans, ' ');
  }
  return ans;
}

int main() {
    char *test = calloc(INT_MAX, 1);
    test = "The sunset sets at twelve o' clock";
    test = alphabet_position(test);
    printf("%s\n", test);
    return (0);
}