/**
 * 127. 单词接龙
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。

 * https://leetcode-cn.com/problems/word-ladder/
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        
        if (!wordSet.count(endWord))
            return 0;
        
        q.push(make_pair(beginWord, 0));
        wordSet.erase(beginWord);
        
        while (!q.empty()) {
            string cur = q.front().first;
            int level  = q.front().second;
            q.pop();
            
            if (cur == endWord)
                return level + 1;
            
            for (int i = 0; i < cur.size(); i++) {
                string tmp = cur;
                for (int j = 0; j < 26; j++) {
                    tmp[i] = 'a' + j;
                    if (wordSet.count(tmp)) {
                        q.push(make_pair(tmp, level + 1));
                        wordSet.erase(tmp);
                    }
                }
            }
        }
        
        return 0;
    }
};
