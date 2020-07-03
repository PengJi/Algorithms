#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // 暴力法
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(1)
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int res = 1, tmp = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < len; i++) {
            if(nums[i] == (nums[i-1] + 1)) {
                tmp += 1;
            } else if(nums[i] == nums[i-1]) {
                continue;
            } else {
                res = max(res, tmp);
                tmp = 1;
            }
        }
        res = max(res, tmp);

        return res;
    }

    // 哈希表
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};

int main() {
    Solution slu;
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    // vector<int> nums = {0, -1};
    vector<int> nums = {1,2,0,1};
    slu.longestConsecutive(nums);
}