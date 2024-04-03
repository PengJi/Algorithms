# 集合

```cpp
// 初始化
vector<int>& nums1;
vector<int>& nums2;
unordered_set<int> s1(nums1.begin(), nums1.end());  // nums1/nums2 也可以是 string

// 常用操作
unordered_set<int> st;

st.insert(x)  // 插入一个数
st.find(x)    // 查找一个数
st.count(x)   // 返回某一个数的个数
st.erase(x)   // 删除数
```
