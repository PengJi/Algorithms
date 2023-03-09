#define LL long long

class Solution {
public:
    // 大顶堆
    LL maxKelements(vector<int>& nums, int k) {
        priority_queue<int> heap(nums.begin(), nums.end());

        LL ans = 0;
        while (k--) {
            int t = heap.top();
            heap.pop();

            ans += t;

            heap.push(ceil((double)(t) / 3));
        }

        return ans;
    }
};
