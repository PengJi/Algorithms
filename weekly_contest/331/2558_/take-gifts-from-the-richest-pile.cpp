#define LL long long

class Solution {
public:
    // 堆
    LL pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> heap(gifts.begin(), gifts.end());

        LL ans = 0;
        for (int x : gifts)
            ans += x;

        while (!heap.empty() && k) {
            --k;

            int t = heap.top();
            heap.pop();

            ans -= t - sqrt(t);
            t = sqrt(t);

            if (t > 1)
                heap.push(t);
        }

        return ans;
    }
};
