class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> v[26];
        for(int i = 0; i < s.size(); i++) {
            v[s[i] - 'a'].push_back(i);
        }
        for(int i = 0; i < 26; i++) {
            if(v[i].size() && distance[i] != (v[i][1] - v[i][0] - 1)) {
                return false;
            }
        }

        return true;
    }
};
