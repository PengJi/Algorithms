/**
 * 166. 分数到小数
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/305/
    string fractionToDecimal(int _n, int _d) {
        long long n = _n, d = _d;
        bool minus = false;
        if(n < 0) minus = !minus, n = -n;
        if(d < 0) minus = !minus, d = -d;
        string res = to_string(n / d);
        n %= d;
        if(!n) {
            if(minus && res != "0") return '-' + res;
            return res;
        }

        res += '.';
        unordered_map<long long, int> hash;
        while(n) {
            if(hash[n]) {
                res = res.substr(0, hash[n]) + '(' + res.substr(hash[n]) + ')';
                break;
            } else {
                hash[n] = res.size();
            }
            n *= 10;
            res += to_string(n / d);
            n %= d;
        }

        if(minus) res = '-' + res;
        return res;
    }
};
