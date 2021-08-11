#include <stdio.h>

void merge(int *array, int h_index, int m_index, int l_index) {
    
}

void merge_sort(int *array, int h_index, int m_index, int l_index) {
    // printf("%d, %d, %d,\n", h_index, m_index, l_index);
    int nm_index = (h_index + l_index) / 2;
    if (nm_index != h_index && nm_index != l_index) {
        merge_sort(array, h_index, nm_index, m_index);
        merge_sort(array, m_index, nm_index, l_index);
    }
    if (nm_index == m_index) printf("%d\n", nm_index);
    merge(array, h_index, m_index, l_index);
}

int main() {
    int hoge [5] = {1, 2, 5, 3, 1};
    int h_index;
    int l_index;
    int m_index;

    h_index = sizeof(hoge)/sizeof(*hoge) - 1;
    l_index = 0;
    m_index = 0;

    merge_sort(hoge, h_index, m_index, l_index);
    for (int i = 0; i < sizeof(hoge)/sizeof(*hoge); i++) {
        // printf("%d\n", hoge[i]);
    }
    return (0);
}