class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(!mp[nums[i]]) mp[nums[i]]++;
            else mp[nums[i]]--;
        }
        
        for (unordered_map<int,int>::iterator it=mp.begin(); it != mp.end(); ++it)
           if(it->second != 0) return false;
        
        return true;
    }
};
