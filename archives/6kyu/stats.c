/// https://www.codewars.com/kata/55b3425df71c1201a800009c/

#include <stdlib.h> /// malloc, free
#include <string.h> /// strlen

#include <stdio.h> /// sprintf

int merge(int *array, int l_index, int m_index, int r_index) {
    int *temp_r;
    int *temp_l;
    int r_len;
    int l_len;

    r_len   = r_index - m_index;
    l_len = m_index + 1 - l_index;

    if (!(temp_r = malloc(r_len * sizeof(*temp_r))))
        return (-1);
    if (!(temp_l = malloc(l_len * sizeof(*temp_l))))
        return (-1);
    
    int r = 0 - 1;
    while(++r < r_len) 
        temp_r[r] = array[m_index + 1 + r];

    int l = 0 - 1;
     while(++l < l_len) 
        temp_l[l] = array[l_index + l];
    
    r = 0;
    l = 0;
    while(r < r_len && l < l_len) {
        if (temp_l[l] < temp_r[r]) 
            array[l_index++] = temp_l[l++];
        else 
            array[l_index++] = temp_r[r++];
    }

    while(r < r_len) 
        array[l_index++] = temp_r[r++];
    
    while(l < l_len) 
        array[l_index++] = temp_l[l++];
    free(temp_l);
    free(temp_r);
    return (0);
}

int merge_sort(int *array, int l_index, int r_index) {
    if (l_index < r_index) {
        int m_index = l_index + (r_index - l_index) / 2;
        merge_sort(array, l_index, m_index);
        merge_sort(array, m_index + 1, r_index);
        if (merge(array, l_index, m_index, r_index) == -1)
            return (-1);
    }
    return (0);
}

char num_padleft_zero(int num, int is_last_digit) {
    if (!is_last_digit && num < 10)
        return ('0');
    int base = (is_last_digit) ? num : num / 10;
    return ('0' + base % 10);
}

void sec_to_HMS(int s, char *ret) {
    int h;
    int m;

    h = s / (60 * 60);
    s -= 60 * 60 * h ;
    m = s / 60;
    s -= 60 * m;
    
    int i = 0;
    int d = 0;
    int num = h;
    while (i < 6 + 2) {
        if (i == 2) {   
            num = m;
            ret[i++] = '|';
        }
        if (i == 5) {
            num = s;
            ret[i++] = '|';
        }
        ret[i++] = num_padleft_zero(num, d % 2);
        d++;
    }
    ret[6 + 2] = '\0';
}

int  is_numchar(char c) {
    return (c >= '0' && c <= '9');
}

int numchar_to_int(char c) {
    return (c - '0');
}

int convert_to_int_array(int *array, char *strg, int *sum, int records, int index) {
    int sec    = 0;
    int digits = 0;
    
    if (index == records)
        return (0);
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
    *sum += sec;
    array[index] = sec;
    if (convert_to_int_array(array, strg, sum, records, index + 1) == -1) 
        return (-1);
}

char* stat(char* strg) {
    int *array;
    int count;
    int index;
    int range;
    int average;
    int median;
    int median_l;
    int median_r;
    char *ret;
    char *average_str;
    char *median_str;
    char *range_str;
    
    count = strlen(strg) + 2; // for missing ", " at the end
    if (count < 2 || count %10 != 0) 
        return "";
    count /= 10;
    if (!(array = (int *)malloc(count  * sizeof(*array))))
        return (NULL);
    if (!(ret = (char *)malloc(50 + 1)))
        return (NULL);
    if (!(average_str = malloc(6 + 2 + 1)))
        return (NULL);
    if (!(range_str = malloc(6 + 2 + 1)))
        return (NULL);
    if (!(median_str = malloc(6 + 2 + 1)))
        return (NULL);
    
    average = 0;
    if (convert_to_int_array(array, strg, &average, count, 0) == -1) 
        return (NULL);
    if (merge_sort(array, 0, count - 1) == -1)
        return (NULL);
  

    average  /= count;
    median_l  = (count % 2 != 0) ? count / 2 : (count - 1) / 2;
    median_r  = (count % 2 != 0) ? count / 2 : (count + 1) / 2;
    median    = (array[median_r] + array[median_l]) / 2;
    range     = array[count - 1] - array[0];
    
    sec_to_HMS(range, range_str);
    sec_to_HMS(average, average_str);
    sec_to_HMS(median, median_str);
    sprintf(ret, "Range: %s Average: %s Median: %s", range_str, average_str, median_str);
    ret[50 + 1] = '\n';
    free(range_str);
    free(average_str);
    free(median_str);
    return (ret);
}

int main() {
    char* l = "02|15|59, 02|47|16, 02|17|20, 02|32|34, 02|17|17, 02|22|00, 02|31|41";
    char *hoge = stat(l);
    printf("%s\n", hoge);
    return (0);
}