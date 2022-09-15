/**
 * 344. 反转字符串
 * https://leetcode-cn.com/problems/reverse-string/
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 0) return;

        int left = 0;
        int right = s.size()-1;
        char tmp;
        while(left < right) {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};
