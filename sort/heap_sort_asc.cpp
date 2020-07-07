#include<iostream>
#include<vector>
using namespace std;

// 从小到大排序
// 大顶堆

// 交换三个节点
void adjust(vector<int>& arr, int len, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int maxIdx = index;

    if(left < len && arr[left] > arr[maxIdx]) maxIdx = left;
    if(right < len && arr[right] > arr[maxIdx]) maxIdx = right;

    if(maxIdx != index) {  // 最大值发生变化，重新调整
        swap(arr[index], arr[maxIdx]);
        adjust(arr, len, maxIdx);
    }
}

// 对列表进行排序
void heapSort(vector<int>& arr) {
    int len = arr.size();
    if(len == 0) return;

    for(int i = len/2 - 1; i >= 0; i--) { // 首先调整最后一个非叶节点
        adjust(arr, len, i);
    }

    for(int i = len-1; i >= 1; i--) {
        swap(arr[0], arr[i]); // 首位元素始终为最大值，交换至末尾
        adjust(arr, i, 0); // 调整剩余部分
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
