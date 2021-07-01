#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

// 从小到大排序
// 大顶堆

// 交换三个节点
void adjust(int arr[], int len, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int maxIdx = index; // maxIdx 问三个数中最大值的下标
    if(left < len && arr[left] > arr[maxIdx]) maxIdx = left;
    if(right < len && arr[right] > arr[maxIdx]) maxIdx = right;
    if(index != maxIdx) { // 最大值发生变化，则交换值，并重新调整
        swap(arr[index], arr[maxIdx]);
        adjust(arr, len, maxIdx);
    }
}

// 对列表进行排序
void heapSort(int arr[], int size) {
    // 先调整最后一个非叶结点
    for(int i = size/2-1; i >= 0; i--) {
        adjust(arr, size, i);
    }

    for(int i = size-1; i >= 1; i--) {
        swap(arr[0], arr[i]); // 将最大值交换至末尾
        adjust(arr, i, 0); // 完成剩余部分的调整
    }
}

int main()
{
    int array[8] = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(array, 8);
    for(auto it: array) {
        cout<<it<<endl;
    }
    return 0;
}
