class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        vector<int> v1(26), v2(26);

        for(char c : s) v1[c - 'a'] += 1;
        for(char c : t) v2[c - 'a'] += 1;

        for(int i = 0; i < 26; i++) {
            if(v1[i] || v2[i]) res += abs(v1[i] - v2[i]);
        }
        
        return res;
    }
};
