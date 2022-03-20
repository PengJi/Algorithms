class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int flag = 0;
        int res = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]){
                if(flag == 1) res++;
                flag = 2;
            } else if(nums[i] < nums[i-1]) {
                if(flag == 2) res++;
                flag = 1;
            }
        }

        return res;
    }
};


class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 1; i < n-1; i++) {
            int l = i-1, r = i+1;
            while(l >= 0 && nums[i] == nums[l]) l--;
            while(r < n && nums[i] == nums[r]) r++;
            
            if(l >= 0 && r < n) {
                if(nums[i] < nums[l] && nums[i] < nums[r] || nums[i] > nums[l] && nums[i] > nums[r]) res++;
            }

            while(i + 1 < n && nums[i] == nums[i+1]) i++;
        }

        return res;
    }
};
