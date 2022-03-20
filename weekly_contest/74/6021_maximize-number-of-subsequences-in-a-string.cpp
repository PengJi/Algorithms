class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0;
        int cnt0 = 0, cnt1 = 0;
        for(auto &t : text) {
            if(t == pattern[1]) {
                res += cnt0;
                cnt1++;
            }
            if(t == pattern[0]) {
                cnt0++;
            }
        }

        return res + max(cnt0, cnt1);
    }
};
