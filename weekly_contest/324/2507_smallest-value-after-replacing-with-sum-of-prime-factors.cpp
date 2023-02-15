class Solution {
public:
    int smallestValue(int n) {
        while (1) {
            int t = n, sum = 0;

            for (int i = 2; i * i <= t; i++)
                while (t % i == 0) {
                    sum += i;
                    t /= i;
                }

            if (t > 1)
                sum += t;

            if (sum == n)
                break;

            n = sum;
        }

        return n;
    }
};
