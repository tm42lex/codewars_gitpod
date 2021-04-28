// https://www.codewars.com/kata/54c27a33fb7da0db0100040e/train/c

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

bool is_square_r(unsigned long long n, int i) {
    unsigned long long square = i * i;
    printf("%d\n", i);
    if (square == n)
        return (true);
    if (square > n)
        return (false);
    if (square * square < n)
        return is_square_r(n, square + 1);
    return is_square_r(n, i + 1);
}

bool is_square(int n) {
    if (n < 0)
        return (false);
    else if (n >= 0 && n < 2)
        return (true);
    else
        return is_square_r((unsigned long long)n, 2);
}

int main(int argv, char **argc) {
    bool ans = is_square(atoi(argc[1]));
    printf("%d\n", ans);
    return (0);
}