遍历map
```c++
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> _map;
    _map[0] = 1;
    _map[1] = 2;
    _map[10] = 10;

    map<int, int>::iterator iter;
    iter = _map.begin();
    while(iter != _map.end()) {
        cout << iter->first << " : " << iter->second << endl;
        iter++;
    }

    // 也可以使用for循环遍历
    /*
    for(iter = _map.begin(); iter != _map.end(); iter++) {
        cout << iter->first << " : " << iter->second << endl;
    }
    */
    return 0;
}
```