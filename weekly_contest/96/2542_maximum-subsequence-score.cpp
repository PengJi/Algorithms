#define LL long long

class Solution {
public:
    LL maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        const int n = nums1.size();

        vector<int> id(n);
        for (int i = 0; i < n; i++)
            id[i] = i;

        sort(id.begin(), id.end(), [&](int x, int y) {
            return nums2[x] > nums2[y];
        });

        LL res = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; i++) {
            sum += nums1[id[i]];
            heap.push(nums1[id[i]]);

            if (i >= k) {
                int t = heap.top();
                heap.pop();
                sum -= t;
            }

            if (i >= k - 1)
                res = max(res, sum * nums2[id[i]]);
        }

        return res;
    }
};
