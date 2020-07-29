/**
 * 692. 前K个高频单词
 * 给一非空的单词列表，返回前 k 个出现次数最多的单词。
 * 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
 * 
 * https://leetcode-cn.com/problems/top-k-frequent-words/
 */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int len = words.size();
        if(len == 0) return {};

        unordered_map<string, int> mp;
        for(int i = 0; i < len; i++) {
            mp[words[i]]++;
        }

        // 小顶堆
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> queue;

        int count = 0;
        auto iter = mp.begin();
        while(iter != mp.end()) {
            if(count == k) break;
            queue.push(*iter);
            count++;
            iter++;
        }

        // 将大于栈顶的元素放入，并删除栈顶
        for(; iter != mp.end(); iter++) {
            if(iter->second > queue.top().second) {
                queue.pop();
                queue.push(*iter);
            }
        }

        vector<string> res;
        for(int i = 0; i < k; i++) {
            res.push_back(queue.top().first);
            queue.pop();
        }

        return res;

    }

    struct cmp {
        bool operator()(pair<string, int> left, pair<string, int> right) {
            // return left.second < right.second;
            return (left.second > right.second || (left.second == right.second && left.first < right.first));
        }
    };
};