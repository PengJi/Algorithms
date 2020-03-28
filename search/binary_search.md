# 二分查找
```python
left, right = 0, len(array) - 1 
while left <= right: 
    mid = (left + right) / 2 
    if array[mid] == target: 
        # find the target!! 
        break or return result 
    elif array[mid] < target: 
        left = mid + 1 
    else: 
        right = mid - 1
```

# 题目
[69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)  
[367. 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)  
[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)  
[74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)  
[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)  