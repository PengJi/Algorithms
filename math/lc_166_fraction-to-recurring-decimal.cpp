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


class Solution {
public:
    // 模拟除法
    // 时间复杂度为 O(n)
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator, d = denominator;

        // 判断正负数
        bool minus = false;
        if(n < 0) minus = !minus, n = -n;
        if(d < 0) minus = !minus, d = -d;

        string res = to_string(n / d);
        n %= d;
        if(!n) {  // 能够除尽，直接返回结果
            if(minus && res != "0") return '-' + res;
            return res;
        }

        // 除不尽则获取循环部分
        res = res + '.';
        unordered_map<int, int> mp;  // 判断循环部分，值为字符串下标
        while(n) {  // 余数不等于0
            if(mp[n]) {  // 找到了第一个循环的下标，返回结果
                res = res.substr(0, mp[n]) + '(' + res.substr(mp[n]) + ')';
                break;
            } else {
                mp[n] = res.size();  // 添加下标
            }

            n *= 10;  // 有余数则向后除
            res += to_string(n / d);  // 更新字符串
            n %= d;  // 求余数
        }

        if(minus) res = '-' + res;
        return res;
    }
};
