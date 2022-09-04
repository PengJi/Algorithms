#define x first
#define y second

typedef long long LL;
typedef pair<LL, int> PIL;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        priority_queue<int, vector<int>, greater<int>> heap;
        priority_queue<PIL, vector<PIL>, greater<PIL>> rooms;
        for (int i = 0; i < n; i ++ ) heap.push(i);

        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n);
        for (auto& p: meetings) {
            while (rooms.size() && rooms.top().x <= p[0]) {
                heap.push(rooms.top().y);
                rooms.pop();
            }
            if (heap.size()) {
                int t = heap.top();
                heap.pop();
                cnt[t] ++ ;
                rooms.push({p[1], t});
            } else {
                auto t = rooms.top();
                rooms.pop();
                cnt[t.y] ++ ;
                rooms.push({t.x + p[1] - p[0], t.y});
            }
        }

        int res = 0;
        for (int i = 1; i < n; i ++ )
            if (cnt[i] > cnt[res])
                res = i;
        return res;
    }
};
