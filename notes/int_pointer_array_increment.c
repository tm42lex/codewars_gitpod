#include <stdlib.h>
#include <stdio.h>

int *solve(const int *arr_in, size_t sz_in, size_t *sz_out) {
    int *arrout;
    
    *sz_out = 0;
    if (!(arrout = malloc(sz_in * sizeof(*arrout))))
        return (NULL);

    size_t index = 0;
    while (index != sz_in) {
        arrout[index] = index;
        printf("%d\n", arrout[index]);
        index++; 
    }
    arrout += (sz_in - 1);
    /// not arrout += (sz_in - 1) * sizeof(*arrout); 
    printf("\n%d\n", *arrout);
}

int main () {
    const int test_arr[6] = {3, 4, 4, 3, 6, 3};
    size_t   hoge = 0;
    int *fuga = solve(test_arr, 6, &hoge);
   
    return (0);
}

//  出力結果
// 0
// 1
// 2
// 3
// 4
// 5

// 5

 ///以上のように、int型のpointerをインクリメント（もしくはーの足し算）をしても、
 ///勝手にコンパイラがメモリの方に合わせて掛け算してくれる。なので手動で掛け算しようとすると結果がおかしくなる