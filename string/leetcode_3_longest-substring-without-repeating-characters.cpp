/**
 * 3. 无重复字符的最长子串
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    // 暴力法（左右指针）
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        if(length == 0) return 0;
        int left = 0, right=0, next = 1, max = 1;
        while(right < length && next < length){
            for(int i = left; i <= right; i++){
                if(s[i] == s[next]){
                    left = i+1;
                }
            }
            if(left > right){
                right = left;
                next++;
            }else{
                right = next;
                next++;
            }
        
            if((right-left + 1) > max){
                max = right - left + 1;
            }
        }

        return max;
    }
};
