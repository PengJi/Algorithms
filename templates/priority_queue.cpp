// 优先级队列
struct Node1 {
    int w, id, tm;
    bool operator< (const Node1& t) const {
        if(tm != t.tm) return tm > t.tm;
        if(w != t.w) return w > t.w;
        return id > t.id;
    }
};

priority_queue<Node1> heap1;
heap1.push({10, 1, 0});
heap1.top();
heap1.pop();
