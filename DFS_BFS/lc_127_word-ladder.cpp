/**
 * 127. 单词接龙
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 *
 * https://leetcode.cn/problems/word-ladder/
 */

class Solution {
public:
    // BFS
    // https://leetcode-cn.com/problems/word-ladder/solution/javacong-bao-li-dao-shuang-xiang-dui-lie-zhu-bu-yo/
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 记录是否访问过
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;  // 队列，用于BFS

        if (!word_set.count(endWord)) return 0;

        q.push({beginWord, 0});
        word_set.erase(beginWord);

        while (!q.empty()) {
            // 出队，取一个元素判断
            string cur = q.front().first;
            int level = q.front().second;
            q.pop();

            if (cur == endWord) return level + 1;

            for (int i = 0; i < cur.size(); i++) {
                string tmp = cur;
                // 相差一个单词
                for (int j = 0; j < 26; j++) {
                    tmp[i] = 'a' + j;
                    if (word_set.count(tmp)) {
                        q.push({tmp, level + 1});  // 入队
                        word_set.erase(tmp);
                    }
                }
            }
        }

        return 0;
    }
};

class Solution {
public:
    // 可转换为求最短路问题。
    // 将单词看做点，如果两个单词可以相互转化，则在相应的点之间连一条无向边，那问题就变成了求从起点到终点的最短路。
    // 枚举每个单词，然后枚举该单词的每一位字母，再枚举这一位的所有备选字母，然后再判断改变后的字符串是否存在。
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;  // 所有单词
        for (auto& x : wordList) st.insert(x);

        unordered_map<string, int> hash;  // 从当前点到起点的最短路径
        hash[beginWord] = 0;

        queue<string> q;  // BFS
        q.push(beginWord);

        while (q.size()) {
            string t = q.front();
            q.pop();

            string r = t;
            for (int i = 0; i < t.size(); i++) {  // 遍历单词的每一位
                t = r;
                for (char j = 'a'; j <= 'z'; j++) {  // 遍历每位字母
                    t[i] = j;
                    if (st.count(t) && !hash.count(t)) {
                        hash[t] = hash[r] + 1;                 // t 的最短路径
                        if (t == endWord) return hash[t] + 1;  // 已经到最后一个单词
                        q.push(t);
                    }
                }
            }
        }

        return 0;
    }
};
