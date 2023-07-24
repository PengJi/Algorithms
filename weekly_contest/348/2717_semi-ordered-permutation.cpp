/**
 * 2717. 半有序排列
 * https://leetcode.cn/problems/semi-ordered-permutation/description/
*/

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size(), one = 0, numN  = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                one = i;
            else if(nums[i]==n){
                numN = i;
            }
        }
        int temp = 0;
        if(one>numN){
            temp = -1;
        }
        return temp+one+(n-1-numN);
    }
};

