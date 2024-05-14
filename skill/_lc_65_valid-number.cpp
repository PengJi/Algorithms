/**
 * 65. 有效数字
 * https://leetcode-cn.com/problems/valid-number/
 */

class Solution {
public:
    // https://www.acwing.com/solution/content/13813/
    // 1. 找到字符串中第一次字符 e 的地方，记为 e_pos。
    // 2. 如果 e_pos 存在，则将字符分为两部分判断，e 之前的部分需要为一个整数或者浮点数。e 之后的部分需要为一个整数。
    // 3. 如果 e_pos 不存在，则整个字符串需要为一个整数或者浮点数。
    // 4. 判断整数或者浮点数时，需要满足一下几点
    // 正负号仅能出现开头
    // 字符串中需要至少有一个数字
    // 判断浮点数时，. 不能出现多次
    bool isNumber(string s) {
        size_t e_pos = s.find('e');
        size_t E_pos = s.find('E');

        if (e_pos != string::npos)
            return isPureNumber(s.substr(0, e_pos), false) && isPureNumber(s.substr(e_pos + 1), true);

        if (E_pos != string::npos)
            return isPureNumber(s.substr(0, E_pos), false) && isPureNumber(s.substr(E_pos + 1), true);

        return isPureNumber(s, false);
    }

    bool isPureNumber(const string &s, bool must_be_integer) {
        if (s.empty()) return false;

        int st = int(s[0] == '+' || s[0] == '-');
        bool has_dot = false, has_digit = false;

        for (int i = st; i < s.size(); i++) {
            if (s[i] == '.') {
                if (must_be_integer) return false;
                if (has_dot) return false;

                has_dot = true;
            } else if (isdigit(s[i])) {
                has_digit = true;
            } else {
                return false;
            }
        }

        return has_digit;
    }
};
