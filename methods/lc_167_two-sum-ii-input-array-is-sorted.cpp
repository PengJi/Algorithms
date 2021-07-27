/**
 * 167. 两数之和 II - 输入有序数组
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/306/
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0, j = numbers.size() - 1; i < j; i++) {
            while(numbers[j] + numbers[i] > target) j--;
            if(numbers[j] + numbers[i] == target) {
                vector<int> res;
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
        }

        return {};
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l = 0, r = numbers.size()-1;
        int tmp;
        while(l < r) {
            tmp = numbers[l] + numbers[r];
            if(tmp > target) r--;
            else if(tmp < target) l++;
            else {
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }
        }

        return res;
    }
};
