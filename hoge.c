#include <stdlib.h>
#include <stdio.h>

int *solve(const int *arr_in, size_t sz_in, size_t *sz_out) {
    *sz_out  = 0;
    size_t i = 0;
    int *arrout;
    int *for_realloc = arrout;

    if (!(arrout = (int *)malloc(sz_in * sizeof(*arrout))))
        return (NULL);
    while (i < sz_in) {
        size_t k = i;
        while (++k < sz_in && arr_in[k] != arr_in[i])
            ;
        if (k == sz_in) {
            (*sz_out)++;
            *arrout = arr_in[i];
            arrout++;
        }
        i++;
    }
    return (realloc(for_realloc, *sz_out));
}

int main () {
    const int test_arr[6] = {3, 4, 4, 3, 6, 3};
    size_t   hoge = 0;
    int *fuga = solve(test_arr, 6, &hoge);
    for (int i = 0; i < 4; i++) {
        printf("%d", fuga[i]);
    }
    return (0);
}
