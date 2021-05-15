/**
 * 275. H 指数 II
 * https://leetcode-cn.com/problems/h-index-ii/
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0 || citations[len-1] == 0) return 0;
        int left = 0, right = len-1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(citations[mid] >= len - mid) right = mid;
            else left = mid + 1;
        }

        return len - left;
    }
};
