# 进制转换

## 十进制转十六进制
```c
#include <stdio.h>

int main() {
    char arr[] = "0123456789ABCDEF";
    int input_num = 0;
    char res[32]; 
    int idx = 0;
    
    scanf("%d", &input_num);

    // 转为十六进制
    while(input_num) {
        res[idx++] = arr[input_num % 16];
        input_num /= 16;
    }

    for(int i = idx - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }
    printf("\n");

    return 0;
}
```

## 十六进制转十进制
```cpp
#include<iostream>
using namespace std;

int main() {
    char arr[] = "0123456789ABCDEF";
    string ss;

    while(cin >> ss) {
        int len = ss.size();
        int k = 1;  // 进位
        int res = 0;

        for(int i = len-1; i >= 0; i--) {
            if(ss[i] >= 'a' && ss[i] <= 'f') ss[i] -= 32;  // 转换为大写

            // 转为十进制
            for(int j = 1; j < 16; j++) {
                if(arr[j] == ss[i]) res += j*k;
            }
            k *= 16;
        }

        cout << res << endl;
    }

    return 0;
}
```
