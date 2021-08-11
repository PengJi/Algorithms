/**
 * 1122. 数组的相对排序
 * 给你两个数组，arr1 和 arr2，
 * arr2 中的元素各不相同
 * arr2 中的每个元素都出现在 arr1 中
 * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。
 * 未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
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
