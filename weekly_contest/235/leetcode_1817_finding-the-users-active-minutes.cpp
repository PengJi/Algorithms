/**
 * 1817. 查找用户活跃分钟数
 * https://leetcode-cn.com/problems/finding-the-users-active-minutes/
 */

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        set<vector<int>> st;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < logs.size(); i++) {
            if(st.count(logs[i]) == 0) st.insert(logs[i]);
            else continue;
            
            int id = logs[i][0];
            if(mp.count(id) == 0) {
                mp.insert({id, 1});
            } else {
                mp.insert({id, mp[id]++});
            }
        }
        
        vector<int> res(k, 0);
        for(auto item : mp) {
            res[item.second-1]++;
        }
        
        return res;
    }
};
