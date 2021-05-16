/**
 * 5743. 增长的内存泄露
 * https://leetcode-cn.com/problems/incremental-memory-leak/
 */

class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        for(int i = 0; ; i++) {
            if(m1 >= m2) {
                if(m1 < i) return {i, m1, m2};
                m1 -= i;
            } else {
                if(m2 < i) return {i, m1, m2};
                m2 -= i;
            }
        }

        return {};
    }
};
