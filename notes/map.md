# 遍历map
```cpp
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> _map;
    _map[0] = 1;
    _map[1] = 2;
    _map[10] = 10;
    /*
    对于 _map[k], 如果 k 不存在则 v 默认为 0
    */

    map<int, int>::iterator iter;
    iter = _map.begin();
    while(iter != _map.end()) {
        cout << iter->first << " : " << iter->second << endl;
        iter++;
    }

    // 可以使用for循环遍历
    for(iter = _map.begin(); iter != _map.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }

    for(auto [k, v] : _map) {
        cout << k << v << endl;
    }

    return 0;
}
```