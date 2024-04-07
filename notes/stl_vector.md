* 变长数组，倍增的思想
```cpp
size()  // 返回元素个数
empty()  // 返回是否为空
clear()  // 清空
front()/back()
push_back()/pop_back()
begin()/end()
insert(v.begin(), 0)  // 队首插入 0
[]
支持比较运算，按字典序
```

* 初始化
```cpp
vector<int> vec;
vector<int> vec(3);  // 3个元素，默认值为0
vector<int> vce(5,3);  // 5个元素，值为3

vector<int> vec1(vec);
vector<int> vec1 = vec; 

vector<int> vec = {1,2,3.0,4,5,6,7};
vector<int> vce {1,2,3.0,4,5,6,7};

// vec 也可以是 set
unordered_set<int> vec;
vector<int> vec;
vector<int> vec1(vec.begin()+2, vec.end()-1);
```

* 妙用
```cpp
vector<int> vec[26];  // 相当于二维数组，有 26个元素，每个元素是一个 vector
vec.push_back(1);  // 第一个 vector 插入一个元素
```

* 排序元素类型为 pair 的 vector
```cpp
// 首先按字符串排序，如果字符串相等，则根据第二个元素排序
vector<pair<string, int>> strs(n);

// 为避免超时，pair<string, int>& a 这里定义为引用
// 时间复杂度 nlogn
sort(strs.begin(), strs.end(), [&](pair<string, int>& a, pair<string, int>& b) {
    // 逐个对比从 trim 后的字符
    for(int i = a.first.size() - trim; i < a.first.size(); i++) {
        if(a.first[i] < b.first[i]) return true;  // 从小到大排序
        else if(a.first[i] > b.first[i]) return false;
    }
    return a.second < b.second;
});
```
[2343. 裁剪数字后查询第 K 小的数字](https://www.acwing.com/activity/content/problem/content/7232/)

* 排序元素类型为 vector 的 vector
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    ...
}

static bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}
```
[56. 合并区间](https://leetcode.cn/problems/merge-intervals/description/)

* 排序元素类型为 int 的 vector
```cpp
nums = [3,30,34,5,9];

// 将 vector 拼接为最大的字符串，上述 vector 结果为 "9534330"。
sort(nums.begin(), nums.end(), [](int x, int y) {
    string a = to_string(x), b = to_string(y);
    return a + b > b + a;
});


// 根据其他元素排序
vector<int>& sid;
unordered_map<int, int> score;  // key 对应 sid
sort(sid.begin(), sid.end(), [&](int x, int y) {
    if (score[x] != score[y])  // 如果序号不等，则根据 value 排序
        return score[x] > score[y];

    return x < y;  // 如果序号相等，序号小的排在前面
});

// 根据某一个位置的元素排序
vector<int> id(m);
sort(id.begin(), id.end(), [&](int x, int y) {
    return score[x][k] > score[y][k];
});
```
