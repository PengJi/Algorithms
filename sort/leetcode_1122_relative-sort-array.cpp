/**
 * 1122. 数组的相对排序
 * 
 * https://leetcode-cn.com/problems/relative-sort-array/
 */

class Solution {
public:
    // 遍历 + 排序
    // 时间复杂度：O(m * n + mlogm)
    // 空间复杂度：O(1)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size(), len2 = arr2.size();
        if(len1 == 0) return {};

        int tmp = 0;  // 相对顺序相同的指针
        for(int i = 0; i < len2; i++) {
            for(int j = 0; j < len1; j++) {
                if(arr2[i] == arr1[j]) {
                    swap(arr1[j], arr1[tmp]);  // 交换arr1中的元素
                    tmp++;  // tmp之前的元素为排好序的元素
                }
            }
        }

        sort(arr1.begin() + tmp, arr1.end());

        return arr1;
    }
};
