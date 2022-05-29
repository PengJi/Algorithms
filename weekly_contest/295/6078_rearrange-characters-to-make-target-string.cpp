class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<char> sv(26), tv(26);  // 哈希表
        for(int i = 0; i < s.size(); i++) sv[s[i] - 'a']++;
        for(int i = 0; i < target.size(); i++) tv[target[i] - 'a']++;

        int res = INT_MAX;
        for(int i = 0; i < tv.size(); i++) {
            if(tv[i] > 0) res = min(res, sv[i]/tv[i]);
        }

        return res;
    }
};