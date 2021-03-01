/**
 * 剑指 Offer 40. 最小的k个数
 * https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 */

class Solution {
public:
    // 排序
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(k)
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; i++) {
            ans[i] = arr[i];
        }

        return ans;
    }

    // 堆
    // 时间复杂度：O(nlogk)
    // 空间复杂度：O(k)
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() == 0 || k == 0) return {};
        vector<int> ans;
        priority_queue<int> pq;
        for(int i = 0; i < arr.size(); i++) {
            if(pq.size() < k) {
                pq.push(arr[i]);
            } else if(pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }

    // 快排
    // 时间复杂度：
    // 空间复杂度：
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
    }
};
