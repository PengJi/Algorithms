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
        if (k >= arr.size()) return arr;
        return quickSort(arr, k, 0, arr.size() - 1);
    }
    
    vector<int> quickSort(vector<int>& arr, int k, int l, int r) {
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        if (i > k) return quickSort(arr, k, l, i - 1);
        if (i < k) return quickSort(arr, k, i + 1, r);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
};


    vector<int> getLeastNumbers(vector<int>& arr, int k) {

    }
private:


作者：jyd
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/jian-zhi-offer-40-zui-xiao-de-k-ge-shu-j-9yze/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
