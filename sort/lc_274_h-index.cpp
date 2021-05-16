/**
 * 274. H 指数
 * https://leetcode-cn.com/problems/h-index/
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for(int h = citations.size(); h > 0; h--) {
            if(citations[h-1] >= h) return h;
        }

        return 0;
    }
};
