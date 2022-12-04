/**
 * 6253. 回环句
 * https://leetcode.cn/problems/circular-sentence/description/
*/

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int len = sentence.size();
        for(int i = 0; i < len; i++) {
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) return false;
        }

        return sentence[0] == sentence[len-1];
    }
};
