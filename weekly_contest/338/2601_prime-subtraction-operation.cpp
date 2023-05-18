const int N = 1010;

class Solution {
public:
    vector<int> p;
    bool mark[N]; // mark(i) 为 false 则是质数

    void init_prime() {
        mark[1] = true;

        for (int i = 2; i < N; i++) {
            if (!mark[i])
                p.push_back(i);

            for (int j = 0; j < p.size() && i * p[j] < N; j++) {
                mark[i * p[j]] = true;

                if (i % p[j] == 0)
                    break;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        init_prime();

        const int n = nums.size();

        for (int i = 0, x = 1; i < n; i++) {
            while (x <= nums[i] && mark[nums[i] - x])
                x++;

            if (x > nums[i])
                return false;

            x++;
        }

        return true;
    }
};
