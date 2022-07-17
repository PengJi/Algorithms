# vector 元素为 pair，排序
```cpp
vector<pair<string, int>> strs(n);
// 首先按字符串排序，如果字符串相等，则根据第二个元素排序
sort(strs.begin(), strs.end(), [&](pair<string, int>& a, pair<string, int>& b) {
    for(int i = a.first.size(); i < a.first.size(); i++) {
        if(a.first[i] < b.first[i]) return true;
        else if(a.first[i] > b.first[i]) return false;
    }
    return a.second < b.second;
});
res.push_back(strs[k-1].second);
```

# 例题
[6121. 裁剪数字后查询第 K 小的数字](https://leetcode.cn/problems/query-kth-smallest-trimmed-number/)