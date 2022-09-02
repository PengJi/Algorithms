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

class Solution {
public:
    string reverseOnlyLetters(string s) {
        string res = s;
        int l = 0, r = res.size()-1;
        while(l < r) {
            if(!isalpha(res[l])) l++;
            if(!isalpha(res[r])) r--;
            if(isalpha(res[l]) && isalpha(res[r]))
                swap(res[l++], res[r--]);
        }

        return res;
    }
};

