/**
 * 5710. 积压订单中的订单总数
 * https://leetcode-cn.com/problems/number-of-orders-in-the-backlog/
 */

class Solution {
public:
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
                        sell.push(cur);
                    }
                }
                if(amount > 0) {
                    buy.push(make_pair(price, amount));
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
                        buy.push(cur);
                    }
                }
                if(amount > 0) {
                    sell.push(make_pair(-price, amount));
                }
            }
        }

        int res;
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


class Solution
{
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) 
    {
        priority_queue<pair<int, int>> sells;
        priority_queue<pair<int, int>> buys;
        for (const auto o : orders) {
            int price = o[0];
            int amount = o[1];
            if (o[2] == 0) {
                // buy
                while (!sells.empty() && amount > 0) {
                    auto t = sells.top();
                    t.first *= -1;
                    if (t.first > price) {
                        break;
                    }
                    sells.pop();
                    int count = min(t.second, amount);
                    amount -= count;
                    t.second -= count;
                    if (t.second > 0) {
                        t.first *= -1;
                        sells.push(t);
                    }
                }
                if (amount > 0) {
                    buys.push(make_pair(price, amount));
                }
            } else {
                // sell
                while (!buys.empty() && amount > 0) {
                    auto t = buys.top();
                    if (t.first < price) {
                        break;
                    }
                    buys.pop();
                    int count = min(t.second, amount);
                    amount -= count;
                    t.second -= count;
                    if (t.second > 0) {
                        buys.push(t);
                    }
                }
                if (amount > 0) {
                    sells.push(make_pair(-price, amount));
                }
            }
        }
        const int MOD = 1000000007;
        int result = 0;
        while (!sells.empty()) {
            auto t = sells.top();
            sells.pop();
            result = (result + t.second) % MOD;
        }
        while (!buys.empty()) {
            auto t = buys.top();
            buys.pop();
            result = (result + t.second) % MOD;
        }
        return result;
    }
};
