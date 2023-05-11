typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    LL findScore(vector<int>& nums) {
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        const int n = nums.size();

        for (int i = 0; i < n; i++)
            heap.push(make_pair(nums[i], i));

        vector<bool> mark(n, false);

        LL ans = 0;
        while (!heap.empty()) {
            PII top = heap.top();
            heap.pop();

            if (mark[top.second])
                continue;

            ans += top.first;

            if (top.second > 0)
                mark[top.second - 1] = true;

            if (top.second < n - 1)
                mark[top.second + 1] = true;
        }

        return ans;
    }
};
