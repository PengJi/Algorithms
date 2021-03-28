/**
 * 1806. 还原排列的最少操作步数
 * https://leetcode-cn.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
 */

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> p;
        for(int i = 0; i < n; i++) p.push_back(i);
        int cnt=0;
        while(true) {
            cnt++;
            translate(p);
            if(check(p)) break;
        }

        return cnt;
    }

    void translate(vector<int>& p) {
        vector<int> a;
        for(int i = 0; i < p.size(); i += 2) a.push_back(p[i]);
        for(int i = 1; i < p.size(); i += 2) a.push_back(p[i]);
        p = a;
    }

    bool check(vector<int> p) {
        for(int i = 0; i < p.size(); i++) 
            if(p[i] != i) return false;
        return true;
    }
};
