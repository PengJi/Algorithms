/**
 * 2766. 重新放置石块
 * https://leetcode.cn/problems/relocate-marbles/description/
*/

class Solution {
public:
    // 哈希表
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> h;
        for(int x: nums) {
            h.insert(x);
        }

        for(int i = 0; i < moveFrom.size(); ++i) {
            int from = moveFrom[i];
            int to = moveTo[i];

            if(h.find(from) == h.end()) {
                continue;
            }
            h.erase(from);
            h.insert(to);
        }

        vector<int> ans(h.begin(), h.end());
        sort(ans.begin(), ans.end());

        return ans;
    }
};
