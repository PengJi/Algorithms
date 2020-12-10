/**
 * 127. 单词接龙
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * https://leetcode-cn.com/problems/word-ladder/
 */

class Solution {
public:
    // BFS
    // https://leetcode-cn.com/problems/word-ladder/solution/javacong-bao-li-dao-shuang-xiang-dui-lie-zhu-bu-yo/
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 记录是否访问过
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;  // 队列，用于BFS

        if(!word_set.count(endWord)) return 0;

        q.push({beginWord, 0});
        word_set.erase(beginWord);

        while(!q.empty()) {
            // 出队，取一个元素判断
            string cur = q.front().first;
            int level = q.front().second;
            q.pop();

            if(cur == endWord) return level + 1;

            for(int i = 0; i < cur.size(); i++) {
                string tmp = cur;
                // 相差一个单词
                for(int j = 0; j < 26; j++) {
                    tmp[i] = 'a' + j;
                    if(word_set.count(tmp)) {
                        q.push({tmp, level+1});  // 入队
                        word_set.erase(tmp);
                    }
                }
            }
        }

        return 0; 
    }
};
