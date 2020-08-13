/**
 * 917. 仅仅反转字母
 * https://leetcode-cn.com/problems/reverse-only-letters/
 */

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.size()-1;
        while(left < right) {
            if(!isalpha(S[left])) left++;
            if(!isalpha(S[right])) right--;

            if(isalpha(S[left]) && isalpha(S[right]))
                swap(S[left++], S[right--]);
        }

        return S;
    }
};
