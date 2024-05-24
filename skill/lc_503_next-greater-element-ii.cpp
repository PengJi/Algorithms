#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 之前思路合并区间实现不太方便，所以又想到比较容易实现的一种思路，本质思路是相同的，也是贪心
// 遍历每个表演者，记录每个表演者在裁判观察区间内出现的次数，
// 对次数最多的表演者使用免错金券，然后对次数第二多的表演者使用免错金券，以此类推，这样总扣分就最小。

// 得到总扣分
// errors 表示扣分
// ranges 表示每个裁判观看的范围
int getTotalReduce(vector<int> errors, vector<pair<int, int>> ranges);

int main() {
    // <!--- start 处理输入 --->
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> errors(n);  // 记录犯错次数
    for(int i = 0; i < n; i++) cin >> errors[i];

    vector<pair<int, int>> ranges(m);  // 裁判观察范围
    int start;
    int end;
    for(int i = 0; i < m; i++) {
        cin >> start >> end;
        ranges[i] = {start, end};
    }
    // <!--- end --->

    // effect 中存储了每个表演者所有的扣分（出现次数）
    // 其值越大，表示所有裁判观看的的范围重合越大，使用免错金券的效果越好
    vector<int> effect(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            start = ranges[j].first;
            end = ranges[j].second;
            // 如果表演者在该裁判的观看范围内，增加其扣分（出现次数）
            if(i >= start -1 && i <= end - 1) {
                effect[i] += 1;
            }
        }
    }

    // 贪心分配免错金券
    int max, best;
    for(int p = 0; p < k; ++p) {
        max = -1;  // 最大减少
        best = -1;  // 能够使总扣分减少最多的表演者

        // 遍历每个表演者，得到扣分效果最优的表演者
        for(int i = 0; i < n; ++i) {
            int cur = INT_MAX;
            if(errors[i] > 0) {  // 只考虑犯错误的表演者
                cur = min(errors[i], effect[i]);  // 免错金券后的扣分减少量
                if(cur > max) {  // 查找最多的减少量
                    max = cur;
                    best = i;  // 记录最优表演者
                }
            }
        }

        cout << best << " " << errors[best] << endl;

        // 找到效果最优的表演者，分配免错金券
        if(best != -1) errors[best] -= 1;
    }

    // 使用调整后的犯错误数计算最小罚分
    int res = getTotalReduce(errors, ranges);
    cout << res << endl;

    return 0;
}

int getTotalReduce(vector<int> errors, vector<pair<int, int>> ranges) {
    int total = 0;
    int start;
    int end;

    // 遍历每个裁判的观看范围
    for(auto& n : ranges) {
        start = n.first;
        end = n.second;

        // 计算该裁判观看的表演者总扣分
        for(int i = start - 1; i < end; ++i) total += errors[i];
    }

    return total;
}
