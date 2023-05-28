class Solution {
public:
    // 贪心、堆
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        const int n = reward1.size();
        priority_queue<int, vector<int>, greater<int>> heap;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += reward1[i];
            heap.push(reward1[i] - reward2[i]);

            if (heap.size() > k) {
                int t = heap.top();
                heap.pop();

                ans -= t;
            }
        }

        return ans;
    }
};
