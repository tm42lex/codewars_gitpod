#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int h_index, int m_index, int l_index) {
    int *temp_h;
    int *temp_l;
    int h_len;
    int l_len;

    h_len = h_index - m_index;
    l_len = m_index - l_index + 1; ///m_index分までどちらかに入れないといけない。単純引き算だと、置いてきぼりになる

    if (!(temp_h = malloc(h_len * sizeof(*temp_h))))
        return ;
    if (!(temp_l = malloc(l_len * sizeof(*temp_l))))
        return ;

    int i = 0 - 1;
    while(++i < h_len) 
        temp_h[i] = array[m_index + i + 1]; ///m_index分を避けるため
    i = 0 - 1;
    while(++i < l_len) 
        temp_l[i] = array[l_index + i];

    int h = 0, l = 0;
    while (h < h_len && l < l_len) {
        if (temp_h[h] < temp_l[l])
            array[l_index++] = temp_h[h++];
        else
            array[l_index++] = temp_l[l++]; 
    }
    while (h < h_len) 
        array[l_index++] = temp_h[h++];
    while (l < l_len)
        array[l_index++] = temp_l[l++];

    free(temp_h);
    free(temp_l);
}

void merge_sort(int *array, int h_index, int l_index) {
    if (l_index < h_index) {
        int m_index = l_index + (h_index - l_index) / 2; //最低値プラス差分の足し算にすることで、int型のオーバーフローがあった時用の対策
        merge_sort(array, h_index, m_index + 1); // + 1 は重複避けるため
        merge_sort(array, m_index, l_index);
        merge(array, h_index, m_index, l_index);
    }
}

int main() {
    int hoge [7] = {1, 2, 5, 3, 1, 0, 2};
    int h_index;
    int l_index;
    int m_index;

    h_index = sizeof(hoge)/sizeof(*hoge) - 1;
    l_index = 0;

    merge_sort(hoge, h_index, l_index);
    for (int i = 0; i < sizeof(hoge)/sizeof(*hoge); i++) {
        printf("%d\n", hoge[i]);
    }
    return (0);
}