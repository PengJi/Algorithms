#include <iostream>
#include <vector>
using namespace std;

// 归并排序（升序）
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        tmp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    }

    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];

    for (int p = 0; p < tmp.size(); p++) {
        arr[left + p] = tmp[p];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) >> 1;  // (left+right)/2

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr{0, 5, 1, 1, 9, 6, 8, 19, 11, 3, 7};
    for (int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, 10);

    for (int i = 0; i < 11; i++) {
        printf("%d ", arr[i]);
    }
}
