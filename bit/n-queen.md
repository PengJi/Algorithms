# n皇后位运算代码示例
```python
def totalNQueens(self, n): 
    if n < 1: return [] 
    self.count = 0 
    self.DFS(n, 0, 0, 0, 0) 
    return self.count

def DFS(self, n, row, cols, pie, na): 
    # recursion terminator 
    if row >= n: 
        self.count += 1 
        return

    bits = (~(cols | pie | na)) & ((1 << n) — 1)  # 得到当前所有的空位

    while bits: 
        p = bits & —bits # 取到最低位的1
        bits = bits & (bits — 1) # 表示在p位置上放入皇后
        self.DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1) 
        # 不需要revert  cols, pie, na 的状态
```

```java
class Solution {
    private int size; 
    private int count;

    private void solve(int row, int ld, int rd) { 
        if (row == size) { 
            count++; 
            return; 
        }
        int pos = size & (~(row | ld | rd)); 
        while (pos != 0) { 
            int p = pos & (-pos); 
            pos -= p; // pos &= pos - 1; 
            solve(row | p, (ld | p) << 1, (rd | p) >> 1); 
        } 
    } 

    public int totalNQueens(int n) { 
        count = 0; 
        size = (1 << n) - 1; 
        solve(0, 0, 0); 
        return count; 
      } 
}
```