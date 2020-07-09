#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];

    while(low < high) {
        while(low < high && pivot > arr[high]) {
            --high;
        }
        arr[low] = arr[high];

        while(low < high && pivot < arr[low]) {
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
    vector<int> arr{0, 5, 1, 9, 6, 8, 19, 11, 3, 7};

    quickSort(arr, 0, 9);

    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}
