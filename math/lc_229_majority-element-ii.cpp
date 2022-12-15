/**
 * 229. 多数元素 II
 * https://leetcode-cn.com/problems/majority-element-ii/
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int r1, r2, c1 = 0, c2 = 0;
        for(auto i : nums) {
            if(c1 && r1 == i) c1++;
            else if(c2 && r2 == i) c2++;
            else if(!c1) r1 = i, c1++;
            else if(!c2) r2 = i, c2++;
            else c1--, c2--;
        }
        c1 = 0, c2 = 0;
        for(auto i : nums) {
            if(r1 == i) c1++;
            else if(r2 == i) c2++;
        }

        vector<int> res;
        int len = nums.size();
        if(c1 > len/3) res.push_back(r1);
        if(c2 > len/3) res.push_back(r2);

        return res;
    }
};

class Solution {
public:
    // 摩尔投票法
    // 可以推广到任意的大于 n/k 的场景
    vector<int> majorityElement(vector<int>& nums) {
        // k 等于 3 时，有两个集合
        int r1, r2, c1 = 0, c2 = 0;
        for(auto x: nums) {
            // 判断属于哪个集合
            if(c1 && r1 == x) c1++;
            else if(c2 && r2 == x) c2++;
            else if(!c1) r1 = x, c1++;
            else if(!c2) r2 = x, c2++;
            // 关键在这里，消除掉两个数
            else c1--, c2--;
        }

        // 统计数目
        c1 = 0, c2 = 0;
        for(auto x: nums) {
            if(x == r1) c1++;
            else if(x == r2) c2++;
        }

        // 统计答案
        vector<int> res;
        int n = nums.size()/3;
        if(c1 > n) res.push_back(r1);
        if(c2 > n) res.push_back(r2);

        return res;
    }
};
