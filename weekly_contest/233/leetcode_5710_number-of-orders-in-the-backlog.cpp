/**
 * 5710. 积压订单中的订单总数
 * https://leetcode-cn.com/problems/number-of-orders-in-the-backlog/
 */

class Solution {
public:
    // 优先队列
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy;
        priority_queue<pair<int, int>> sell;
        int price, amount;
        pair<int, int> cur;
        for(auto item : orders) {
            price = item[0];
            amount = item[1];
            if(item[2] == 0) {
                // buy
                while(!sell.empty() && amount > 0) {
                    cur = sell.top();
                    cur.first *= -1;
                    if(cur.first > price) {
                        break;
                    }
                    sell.pop();
                    if(amount > cur.second) {
                        amount -= cur.second;
                    } else if(amount < cur.second) {
                        cur.first *= -1;
                        cur.second -= amount;
                        amount = 0;
                        sell.push(cur);  // 加入 sell 队列
                    } else {
                        amount = 0;
                    }
                }
                if(amount > 0) {
                    buy.push(make_pair(price, amount));  // 更新 buy 队列
                }
            } else {
                // sell
                while(!buy.empty() && amount > 0) {
                    cur = buy.top();
                    if(price > cur.first) {
                        break;
                    }
                    buy.pop();
                    if(amount > cur.second) {
                        amount -= cur.second;
                    } else if(amount < cur.second) {
                        cur.second -= amount;
                        amount = 0;
                        buy.push(cur);  // 加入 buy 队列
                    } else {
                        amount = 0;
                    }
                }
                if(amount > 0) {
                    sell.push(make_pair(-price, amount));  // 更新 sell 队列
                }
            }
        }

        int res = 0;
        const int MOD = 1e9 + 7;
        while(!buy.empty()) {
            cur = buy.top();
            buy.pop();
            res = (res + cur.second) % MOD;
        }
        while(!sell.empty()) {
            cur = sell.top();
            sell.pop();
            res = (res + cur.second) % MOD;
        }

        return res;
    }
};
