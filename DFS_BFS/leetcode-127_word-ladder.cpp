/**
 * 127. 单词接龙
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