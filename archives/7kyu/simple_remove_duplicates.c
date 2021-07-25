///https://www.codewars.com/kata/5ba38ba180824a86850000f7/train/c
#include <stdlib.h>
#include <stdio.h>

int *solve(const int *arr_in, size_t sz_in, size_t *sz_out) {
    *sz_out  = 0;
    size_t i = 0;
    int *arrout;

    if (!(arrout = (int *)malloc(sz_in * sizeof(*arrout))))
        return (NULL);
    while (i < sz_in) {
        size_t k = i;
        while (++k < sz_in && arr_in[k] != arr_in[i])
            ;
        if (k == sz_in) {
            printf("%d\n", arr_in[i]);
            (*sz_out)++;
            *arrout = arr_in[i];
            arrout++;
        }
        i++;
    }
    return (realloc(arrout - *sz_out, *sz_out * sizeof(*arrout)));
    /// Need to multply by 4, because realloc demands #of memory in the second argument, not # of elements
}

int main () {
    const int test_arr[126] = {24, 32, 10, 39, 44, 6, 51, 14, 33, 10, 48, 58, 3, 24, 9, 5, 45, 31, 24, 15, 11, 18, 9, 32, 63, 16, 3, 20, 36, 6, 29, 57, 34, 37, 31, 14, 40, 18, 24, 6, 26, 8, 62, 26, 28, 6, 27, 8, 34, 49, 21, 41, 2, 27, 6, 62, 41, 8, 15, 13, 10, 42, 5, 42, 13, 32, 52, 51, 46, 12, 53, 6, 16, 50, 30, 42, 52, 53, 48, 19, 37, 2, 58, 35, 27, 61, 30, 2, 4, 43, 11, 10, 19, 12, 50, 28, 42, 38, 12, 22, 46, 63, 26, 60, 46, 52, 37, 31, 40, 18, 49, 10, 16, 40, 41, 42, 36, 5, 40, 38, 44, 49, 44, 61, 59, 30};
    size_t   hoge = 0;
    int *fuga = solve(test_arr, 126, &hoge);
    // for (int i = 0; i < 54; i++) {
    //     printf("%d\n", fuga[i]);
    // }
    return (0);
}
