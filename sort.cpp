#include "sort.h"
#include "pch.h"

int rec = 0, cp=0;

void QuickSort(record* arr[4000], int l, int r, int k) {
    int x = arr[l]->sum, i = l, j = r;
    char y[10];
    for (int z = 0; z < 10; z++)
        y[z] = arr[l]->date[z];
    k++;
    while (i <= j) {
        while (cp++, arr[i]->sum < x) {
            for (int z = 0; z < 10; z++) {
                if (arr[i]->date[z] < y[z]) {
                    i++;
                    break;
                }
            }
        }
        while (cp++, arr[j]->sum > x)
            for (int z = 0; z < 10; z++) {
                if (arr[j]->date[z] > y[z]) {
                    i++;
                    break;
                }
            }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (l < j) QuickSort(arr, l, j, k);
    if (i < r) QuickSort(arr, i, r, k);
    if (rec < k) rec = k;
}
void copy_base(record* arr[4000], record* sarr[4000]) {
    for (int c = 0; c < 4001; c++)
        sarr[c] = arr[c];
}