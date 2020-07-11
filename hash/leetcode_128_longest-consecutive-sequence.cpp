/**
 * 128. 最长连续序列
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 要求算法的时间复杂度为 O(n)。
 * 
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/
 */

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // 哈希表
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        unordered_set<int> numsSet;
        for(int i = 0; i < len; i++) {
            numsSet.insert(nums[i]);
        }

        int res = 0;
        int curLen, curNum;
        for(auto num : numsSet) {  // 遍历set
            if(!numsSet.count(num - 1)) {  // 上一个元素是否存在
                curLen = 0;
                curNum = num;

                while(numsSet.count(curNum)) {  // 下一个元素是否存在
                    curLen++;
                    curNum++;
                }

                res = max(curLen, res);
            }
        }

        return res;   
    }

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
};

int main() {
    Solution slu;
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    // vector<int> nums = {0, -1};
    vector<int> nums = {1,2,0,1};
    slu.longestConsecutive(nums);
}
