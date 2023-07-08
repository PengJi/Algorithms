# 遍历map

```cpp
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> mp;
    mp[0] = 1;
    mp[1] = 2;
    mp[10] = 10;
    /*
    对于 mp[k], 如果 k 不存在则 v 默认为 0
    */

    map<int, int>::iterator iter;
    iter = mp.begin();
    while(iter != mp.end()) {
        cout << iter->first << " : " << iter->second << endl;
        iter++;
    }

    // 可以使用for循环遍历
    for(iter = mp.begin(); iter != mp.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }

    // 第二种方式
    for(auto &[k, v] : mp) {
        cout << k << v << endl;
    }

    // 第三种方式
    for(auto item: mp) {
        cout << item.first << item.second << endl;
    }

    return 0;
}
```