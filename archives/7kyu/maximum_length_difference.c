#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void get_smallest_biggest(const char **array, size_t index, int *smallest, int *biggest) {
    int length = 0;
    while(array[index][length])
        length++;
    if (length < *smallest)
        *smallest = length;
    if (length > *biggest)
        *biggest  = length;
    if (index > 0)
        get_smallest_biggest(array, --index, smallest, biggest);
}

int mxdiflg(
  const char **firstArray, size_t firstArrayLength, 
  const char **secondArray, size_t secondArrayLength) {
    
    if (firstArrayLength == 0 || secondArrayLength == 0) {
      return -1;
    }
    int smallest_f = INT_MAX;
    int smallest_s = INT_MAX;
    int biggest_f  = INT_MIN;
    int biggest_s  = INT_MIN;
    
    get_smallest_biggest(firstArray, firstArrayLength - 1, &smallest_f, &biggest_f);
    get_smallest_biggest(secondArray, secondArrayLength - 1, &smallest_s, &biggest_s);

    int diff_fs = abs(biggest_f - smallest_s);
    int diff_sf = abs(biggest_s - smallest_f);
    return (diff_fs > diff_sf) ? diff_fs : diff_sf;
}

int main () {
    const char *firstArray[] = { "hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz" };
    const char *secondArray[] = { "cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww" };
    
    const size_t firstArrayLength = sizeof(firstArray)/sizeof(firstArray[0]);
    const size_t secondArrayLength = sizeof(secondArray)/sizeof(secondArray[0]);
    
    const int expected = 13;
    const int actual = mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);      
            
    // cr_assert_eq(expected, actual, "Expected: %d Actual: %d", expected, actual);
    printf("%d : actual\n", (int)actual);
    printf("%d : expected\n",(int) expected);

    return (0);
  }
