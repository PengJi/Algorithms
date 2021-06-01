/**
 * 5774. 使用服务器处理任务
 * https://leetcode-cn.com/problems/process-tasks-using-servers/
 */

class Solution {
public:
    struct Node1 {
        int w, id, tm;
        bool operator< (const Node1& t) const {
            if(tm != t.tm) return tm > t.tm;
            if(w != t.w) return w > t.w;
            return id > t.id;
        }
    };

    struct Node2 {
        int w, id, tm;
        bool operator< (const Node2& t) const {
            if(w != t.w) return w > t.w;
            return id > t.id;
        }
    };

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<Node1> heap1;  // 非空闲
        priority_queue<Node2> heap2;  // 空闲

        for(int i = 0; i < servers.size(); i++) heap2.push({servers[i], i, 0});
        vector<int> res;
        for(int i = 0; i < tasks.size(); i++) {
            while(heap1.size() && heap1.top().tm <= i) {
                Node1 t = heap1.top();
                heap2.push({t.w, t.id, t.tm});
                heap1.pop();
            }

            if(heap2.size()) {
                Node2 t = heap2.top();
                heap2.pop();
                res.push_back(t.id);
                heap1.push({t.w, t.id, i + tasks[i]});
            } else {
                Node1 t = heap1.top();
                heap1.pop();
                res.push_back(t.id);
                heap1.push({t.w, t.id, t.tm+tasks[i]});
            }
        }

        return res;
    }
};
