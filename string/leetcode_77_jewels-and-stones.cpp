/**
 * 771. 宝石与石头
 * https://leetcode-cn.com/problems/jewels-and-stones/
 */

class Solution {
public:
    // 哈希
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel;
        for(int i = 0; i < J.size(); i++) {
            jewel.insert(J[i]);
        }

        int ans = 0;
        for(int i = 0; i < S.size(); i++) {
            if(jewel.count(S[i])) {
                ans++;
            }
        }

        return ans;
    }
};
