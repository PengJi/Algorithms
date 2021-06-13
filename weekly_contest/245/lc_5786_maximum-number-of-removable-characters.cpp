/**
 * 5786. 可移除字符的最大数目
 * https://leetcode-cn.com/problems/maximum-number-of-removable-characters/
 */

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size();
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(mid, s, p, removable)) l = mid + 1;
            else r = mid;
        }

        return r;
    }

    bool check(int mid, string s, string p, vector<int>& removable) {
        int len = s.size();
        bool* pos = new bool[len];
        
        for(int i = 0; i < len; i++) pos[i] = false;
        for(int i = 0; i <= mid; i++) pos[removable[i]] = true;

        int i = 0, j = 0;
        while(i < len && j < p.size()) {
            if(pos[i]) {
                i++;
                continue;
            }

            if(s[i] == p[j]) j++;
            i++;
        }

        delete[] pos;
        return j == p.size();
    }
};
