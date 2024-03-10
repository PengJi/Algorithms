/**
 * 126. 单词接龙 II
 * https://leetcode.cn/problems/word-ladder-ii/
 */
class Solution {
public:
    // BFS
    // https://leetcode-cn.com/problems/word-ladder-ii/solution/bfsdfs-by-joy-teng/
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end());
        if (wl.count(endWord) == 0) return {};

        unordered_map<string, unordered_set<string>> trace;
        unordered_set<string> q = {beginWord};
        unordered_set<string> visited;

        for (; q.size() && trace.count(endWord) == 0; q = visited) {
            for (const string &word : q)
                wl.erase(word);

            visited.clear();
            for (const string &word : q) {
                for (int i = 0; i < word.length(); ++i) {
                    string s = word;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (word[i] == ch) continue;
                        s[i] = ch;
                        if (wl.find(s) == wl.end()) continue;
                        trace[s].insert(word);
                        visited.insert(s);
                    }
                }
            }
        }

        if (trace.size() == 0) return {};
        vector<vector<string>> ans;
        dfs(trace, endWord, {}, ans);

        return ans;
    }

    void dfs(unordered_map<string, unordered_set<string>> &trace, const string &last, vector<string> path, vector<vector<string>> &result) {
        path.push_back(last);

        if (trace.count(last) == 0) {
            reverse(path.begin(), path.end());
            result.push_back(path);
            return;
        }

        for (const string &word : trace[last])
            dfs(trace, word, path, result);
    }
};

class Solution {
public:
    unordered_set<string> S;
    unordered_map<string, int> dist;
    queue<string> q;
    vector<vector<string>> ans;
    vector<string> path;
    string beginWord;

    vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string> &wordList) {
        for (auto word : wordList) S.insert(word);
        beginWord = _beginWord;
        dist[beginWord] = 0;
        q.push(beginWord);
        while (q.size()) {
            auto t = q.front();
            q.pop();

            string r = t;
            for (int i = 0; i < t.size(); i++) {
                t = r;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (S.count(t) && dist.count(t) == 0) {
                        dist[t] = dist[r] + 1;
                        if (t == endWord) break;
                        q.push(t);
                    }
                }
            }
        }

        if (dist.count(endWord) == 0) return ans;
        path.push_back(endWord);
        dfs(endWord);
        return ans;
    }

    void dfs(string t) {
        if (t == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            string r = t;
            for (int i = 0; i < t.size(); i++) {
                t = r;
                for (char j = 'a'; j <= 'z'; j++) {
                    t[i] = j;
                    if (dist.count(t) && dist[t] + 1 == dist[r]) {
                        path.push_back(t);
                        dfs(t);
                        path.pop_back();
                    }
                }
            }
        }
    }
};
