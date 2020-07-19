#include<iostream>
#include<vector>
using namespace std;

// 快排（降序）

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];

    while(low < high) {
        while(low < high && pivot >= arr[high]) {
            --high;
        }
        arr[low] = arr[high];

        while(low < high && pivot <= arr[low]) {
            ++low;
        }
        arr[high] = arr[low];
    }

    arr[low] = pivot;
    return low;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid-1);
        quickSort(arr, mid+1, high);
    }
}

int main() {
    vector<int> arr{3,2,3,1,2,4,5,5,6};

    quickSort(arr, 0, 8);

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}
