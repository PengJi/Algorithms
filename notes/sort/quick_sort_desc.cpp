#include <iostream>
#include <vector>
using namespace std;

// 快排（降序）
int sort(vector<int>& arr, int left, int right) {
    int pivot = arr[left];

    while (left < right) {
        while (left < right && pivot >= arr[right]) right--;  // 降序
        arr[left] = arr[right];

        while (left < right && pivot <= arr[left]) left++;  // 降序
        arr[right] = arr[left];
    }

    arr[left] = pivot;
    return left;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = sort(arr, left, right);  // mid 位置的元素确定
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

int main() {
    vector<int> arr{3, 2, 3, 1, 2, 4, 5, 5, 6, 8};

    quickSort(arr, 0, 9);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}
