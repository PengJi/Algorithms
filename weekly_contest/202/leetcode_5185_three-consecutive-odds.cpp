/**
 * 5185. 存在连续三个奇数的数组
 * 给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 true ；否则，返回 false 。
 */

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 0; i + 2 < arr.size(); i++) {
            if(arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2) return true;
        }

        return false;
    }
};
