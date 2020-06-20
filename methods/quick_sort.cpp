/**
 * 快速排序
 */

#include<stdio.h>

int parittition(int arr[], int low, int high) {
    int pivot = arr[low];

    while(low < high) {
        while(low < high && pivot <= arr[high]) {
            --high;
        }
        arr[low] = arr[high];

        while(low < high && pivot >= arr[low]) {
            ++low;
        }
        arr[high] = arr[low];
    }

    arr[low] = pivot;
    return low;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = parittition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }

}

int main() {
    int arr[10] = {0, 5, 1, 9, 6, 8, 19, 11, 3, 7};
    for(int i = 0;i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, 9);

    for(int i = 0;i < 10; i++){
        printf("%d ",arr[i]);
    }
}
