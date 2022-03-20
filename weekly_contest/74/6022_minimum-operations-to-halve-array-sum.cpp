class Solution {
public:
    int halveArray(vector<int>& nums) {
        int res = 0;
        priority_queue<double> pq;
        long long sum = 0;
        for(auto &n : nums) {
            sum += n;
            pq.push((double)n);
        }

        double sum_half = (double) sum / 2;
        double cur = 0.0, sub = 0.0;
        while(sub < sum_half) {
            cur = pq.top();
            pq.pop();
            cur /= 2;
            pq.push(cur);
            sub += cur;
            res++;
        }

        return res;
    }
};
