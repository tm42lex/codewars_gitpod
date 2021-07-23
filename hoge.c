#include <stdlib.h>
#include <stdio.h>

int *solve(const int *arr_in, size_t sz_in, size_t *sz_out) {
    int *arrout;
    
    *sz_out = 0;
    sz_in = (sz_in == 0) ? 0 : sz_in - 1;
    if (!(arrout = malloc(sz_in * sizeof(*arrout))))
        return (NULL);
    arrout += sz_in * sizeof(*arrout);
    while (sz_in--) {
        size_t i = 0;
        while (i < *sz_out && arrout[i] != arr_in[sz_in]) {
            i++;
        }
        if (i == *sz_out) {
            *arrout =  arr_in[sz_in];
            arrout--;
            (*sz_out)++;
        }
    }
  return arrout++;
}

int main () {
    const int test_arr[6] = {3, 4, 4, 3, 6, 3};
    size_t   hoge = 0;
    int *fuga = solve(test_arr, 6, &hoge);
    printf("\n%ld\n", hoge);
    printf("%d", *fuga);

    return (0);
}