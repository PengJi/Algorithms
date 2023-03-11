struct Pending {
    int idx, l2r, r2l;

    Pending(int idx, int l2r, int r2l) {
        this->idx = idx;
        this->l2r = l2r; this->r2l = r2l;
    }

    bool operator < (const Pending &w) const {
        if (w.l2r + w.r2l != l2r + r2l)
            return w.l2r + w.r2l > l2r + r2l;

        return w.idx > idx;
    }
};

struct Doing {
    int idx, finishedTime;

    Doing(int idx, int finishedTime) {
        this->idx = idx;
        this->finishedTime = finishedTime;
    }

    bool operator < (const Doing &w) const {
        return w.finishedTime < finishedTime;
    }
};

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<Pending> left, right;
        priority_queue<Doing> pick, put;
        Doing *bridgeLR = nullptr, *bridgeRL = nullptr;

        for (int i = 0; i < k; i++)
            left.push(Pending(i, time[i][0], time[i][2]));

        int currentTime = 0, finished = 0, remaining = n;
        int ans = 0;

        while (1) {
            int miTime = INT_MAX;

            if (!pick.empty()) miTime = min(miTime, pick.top().finishedTime);
            if (!put.empty()) miTime = min(miTime, put.top().finishedTime);
            if (bridgeLR) miTime = min(miTime, bridgeLR->finishedTime);
            if (bridgeRL) miTime = min(miTime, bridgeRL->finishedTime);

            if (miTime != INT_MAX) {
                while (!pick.empty()) {
                    auto t = pick.top();

                    if (t.finishedTime > miTime)
                        break;

                    pick.pop();
                    right.push(Pending(t.idx, time[t.idx][0], time[t.idx][2]));
                }

                while (!put.empty()) {
                    auto t = put.top();

                    if (t.finishedTime > miTime)
                        break;

                    finished++;

                    put.pop();
                    left.push(Pending(t.idx, time[t.idx][0], time[t.idx][2]));
                }

                if (bridgeLR && bridgeLR->finishedTime == miTime) {
                    pick.push(Doing(bridgeLR->idx, miTime + time[bridgeLR->idx][1]));
                    bridgeLR = nullptr;
                }

                if (bridgeRL && bridgeRL->finishedTime == miTime) {
                    // 更新到达左岸的最晚时间
                    ans = max(ans, miTime);

                    put.push(Doing(bridgeRL->idx, miTime + time[bridgeRL->idx][3]));
                    bridgeRL = nullptr;
                }

                currentTime = miTime;
            }

            // 全部箱子移动完成，结束
            if (finished == n)
                break;

            // 如果桥上有工人正在通行，则不安排上桥
            if (bridgeLR || bridgeRL)
                continue;

            // 如果右侧有等待上桥的工人，则右侧工人可以上桥
            if (!right.empty()) {
                auto t = right.top();
                right.pop();

                bridgeRL = new Doing(t.idx, currentTime + time[t.idx][2]);
            } else if (!left.empty() && remaining > 0) {
                // 右侧没有等待上桥的工人，如果还有剩余的旧箱子，则左侧工人可以上桥
                auto t = left.top();
                left.pop();

                remaining--;

                bridgeLR = new Doing(t.idx, currentTime + time[t.idx][0]);
            }
        }

        return ans;    
    }
};
