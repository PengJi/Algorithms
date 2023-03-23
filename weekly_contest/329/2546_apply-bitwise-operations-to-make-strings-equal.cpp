class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        const int n = s.size();
        bool s0 = true, t0 = true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') s0 = false;
            if (target[i] == '1') t0 = false;
        }

        return (s0 && t0) || (!s0 && !t0);
    }
};
