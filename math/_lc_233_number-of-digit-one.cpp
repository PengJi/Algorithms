/**
 * 233. 数字 1 的个数
 * https://leetcode-cn.com/problems/number-of-digit-one/
 */

class Solution {
public:
    // https://www.acwing.com/activity/content/code/content/439480/
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        vector<int> nums;
        while (n) nums.push_back(n % 10), n /= 10;
        reverse(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i ++ ) {
            int d = nums[i];
            int left = 0, right = 0, p = 1;
            for (int j = 0; j < i; j ++ ) left = left * 10 + nums[j];
            for (int j = i + 1; j < nums.size(); j ++ ) {
                right = right * 10 + nums[j];
                p = p * 10;
            }
            if (d == 0) res += left * p;
            else if (d == 1) res += left * p + right + 1;
            else res += (left + 1) * p;
        }
        return res;
    }
};

class Solution {
public:
    // https://www.acwing.com/solution/content/280/，没理解
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;

        vector<int> f(10, 0), pow(10, 0);
        f[0] = 0;
        pow[0] = 1;
        for (int i = 1; i <= 9; i++) {
            f[i] = f[i - 1] * 10 + pow[i - 1];
            pow[i] = pow[i - 1] * 10;
        }

        string num = to_string(n);
        reverse(num.begin(), num.end());
        int ans = 0, ones = 0;

        for (int i = num.length() - 1; i >= 0; i--) {
            ans += ones * ((num[i] - '0') * pow[i]);
            if (num[i] == '1') {
                ones++;
                ans += f[i];
            }
            else if (num[i] != '0')
                ans += pow[i] + f[i] * (num[i] - '0');
        }

        return ans + ones;
    }
};
