/**
 * 5484. 找出第 N 个二进制字符串中的第 K 位
 * https://leetcode-cn.com/problems/find-kth-bit-in-nth-binary-string/
 */

class Solution {
public:
    char findKthBit(int n, int k) {
        string cur = "0";
        string last;
        while(cur.size() < k) {
            last = cur;
            cur += '1';

            for(char& c : last) {
                c = c == '1' ? '0' : '1';
            }
            reverse(last.begin(), last.end());

            cur += last;
        }

        return cur[k-1];
    }
};
