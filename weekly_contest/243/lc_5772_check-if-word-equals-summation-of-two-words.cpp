/**
 * 5772. 检查某单词是否等于两单词之和
 * https://leetcode-cn.com/problems/check-if-word-equals-summation-of-two-words/
 */

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return  strToInt(firstWord) + strToInt(secondWord) == strToInt(targetWord);
    }
    
    int strToInt(string str) {
        int val = 0;
        for(auto x : str) {
            val = val * 10 + (x - 'a');
        }
        return val;
    }
};
