class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, int> mp;
        int idx = 0;
        for(int i = 0; i < key.size(); i++) {
            if(key[i] != ' ' && mp.count(key[i]) == 0) mp[key[i]] = idx++;
        }
        string res = message;
        for(int i = 0; i < res.size(); i++) {
            if(res[i] != ' ') res[i] = mp[res[i]] + 'a';
        }
        
        return res;
    }
};
