#include<iostream>
#include<vector>
using namespace std;

// 从大到小排序
// 小顶堆

// 调整以 idx 为根的子树
void adjust(vector<int>& arr, int len, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int minIdx = idx;

    if(left < len && arr[left] < arr[minIdx]) minIdx = left;
    if(right < len && arr[right] < arr[minIdx]) minIdx = right;

    if(idx != minIdx) {  // 最小值发生变化，则重新调整
        swap(arr[idx], arr[minIdx]);
        adjust(arr, len, minIdx);
    }
}

void heapSort(vector<int>& arr) {
    int len = arr.size();
    if(len == 0) return;

    // 建堆
    for(int i = len/2-1; i >= 0; i--) { // 先调整最后一个非叶结点
        adjust(arr, len, i);
    }

    for(int i = len-1; i >= 1; i--) {
        swap(arr[0], arr[i]);  // 将最小值交换至末尾
        adjust(arr, i, 0);  // 完成剩余部分调整
    }
}

int main()
{
    vector<int> arr{8, 1, 14, 3, 21, 5, 7, 10};

    heapSort(arr);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
