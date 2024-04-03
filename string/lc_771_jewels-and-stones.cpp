/**
 * 771. 宝石与石头
 * https://leetcode-cn.com/problems/jewels-and-stones/
 */

class Solution {
public:
    // 哈希
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewel;
        for (int i = 0; i < J.size(); i++) {
            jewel.insert(J[i]);
        }

        int ans = 0;
        for (int i = 0; i < S.size(); i++) {
            if (jewel.count(S[i])) {
                ans++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    // 哈希表
    int numJewelsInStones(string jewels, string stones) {
        // 存储类型，直接初始化
        unordered_set<char> st(jewels.begin(), jewels.end());
        int res = 0;
        // 统计个数
        for (auto c : stones) res += st.count(c);

        return res;
    }
};
