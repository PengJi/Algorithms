/**
 * 5761. 找出和为指定值的下标对
 * https://leetcode-cn.com/problems/finding-pairs-with-a-certain-sum/
 */

class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> cnt;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1, n2 = nums2;
        for(auto x : n2) {
            cnt[x]++;
        }
    }
    
    void add(int index, int val) {
        int old = n2[index];
        n2[index] += val;
        cnt[old]--;
        cnt[n2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(auto x : n1) {
            int val = tot - x;
            if(cnt.count(val)) res += cnt[val];
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
