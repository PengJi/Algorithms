/**
 * 347. 前 K 个高频元素
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * https://leetcode-cn.com/problems/top-k-frequent-elements/
 */

class Solution {
public:
    struct CmpByValue {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second; 
        }
    };

    // 使用STL排序算法对value进行排序  
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //统计次数 可以使用map 或 hash map
        map<int, int> m;
        //unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            ++m[nums.at(i)];
        }

        //根据value(统计次数)排序
        vector<pair<int, int> > v(m.begin(), m.end());
        
        //快速排序
        sort(v.begin(), v.end(), CmpByValue()); //从大到小

        //堆排序
        //std::make_heap(v.begin(), v.end(), CmpByValue());
        //std::sort_heap(v.begin(), v.end(), CmpByValue());

        //将前k个数值放入结果数组
        vector<int> k_frequent(k);
        for (int i = 0; i < k; ++i)
        {
            k_frequent.at(i) = v.at(i).first;
        }

        return k_frequent;
    }


    // 桶排序 
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //统计次数
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            ++m[nums.at(i)];
        }

        //使用二维数组  统计次数作为第一维（如果统计次数有相同，则将值追加到桶中）
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            buckets.at(iter->second).push_back(iter->first);
        }

        //将buckets中前k个高频元素放入res中
        vector<int> res(k);
        int count = 0;
        for (int i = buckets.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < buckets.at(i).size(); ++j)
            {
                res.at(count) = buckets.at(i).at(j);
                ++count;
                if (count == k)
                    return res;
            }
        }

        return res;
    }

    // 使用STL 优先队列(堆) 最小堆 大小为K  
    // 时间复杂度：O(nlogk)
    // 空间复杂度：O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计次数
        //map<int, int> m;
        unordered_map<int, int> m; //<值，次数>

        for (int i = 0; i < nums.size(); ++i)
        {
            ++m[nums.at(i)];
        }

        //放入优先队列  注意：> 为小堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, CmpByValue> heap;

        int count = 0;
        auto iter = m.begin();
        for (; iter != m.end(); ++iter)
        {
            if (count == k)
            {
                break;
            }

            heap.push(*iter);

            ++count;
        }

        //将大于堆顶的元素放入 并删除堆顶
        for (; iter != m.end(); ++iter)
        {
            if (iter->second > heap.top().second)
            {
                heap.pop();
                heap.push(*iter);
            }
        }

        vector<int> res(k);
        for (int i = 0; i < k; ++i)
        {
            res.at(i) = heap.top().first;
            heap.pop();
        }

        return res;
    }


    // 使用STL 优先队列(堆) 最大堆 大小为N 
    // 时间复杂度：O(n + klogn)
    // 空间复杂度：O(n)
    struct CmpByValueLess {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second < rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计次数
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            ++m[nums.at(i)];
        }

        //放入优先队列
        //注意：使用STL的优先队列 priority_queue  Comparator = greater 为小堆；Comparator = less 为大堆   
        priority_queue<pair<int, int>, vector<pair<int, int>>, CmpByValueLess> queue;
        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            queue.push(*iter);
        }

        vector<int> res(k);
        for (int i = 0; i < k; ++i)
        {
            res.at(i) = queue.top().first;
            queue.pop();
        }

        return res;
    }
};
