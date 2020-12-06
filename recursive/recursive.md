# 递归
```python
def recursion(level, param1, param2, ...): 
    # recursion terminator 
    if level > MAX_LEVEL: 
       process_result 
       return 

    # process logic in current level 
    process(level, data...) 

    # drill down 
    self.recursion(level + 1, p1, ...) 

    # reverse the current level status if needed
```

```java
public void recur(int level, int param) { 

  // terminator 
  if (level > MAX_LEVEL) { 
    // process result 
    return; 
  } 

  // process current logic 
  process(level, param); 

  // drill down 
  recur(level: level + 1, newParam); 

  // restore current status 
 
}
```

# 题目
- [x] [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)  
- [x] [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)  
- [x] [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/description/)  
- [x] [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)  
- [x] [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)  
- [x] [111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)  
- [x] [297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)  
- [x] [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)  
- [x] [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)  
- [x] [77. 组合](https://leetcode-cn.com/problems/combinations/)  
- [x] [46. 全排列](https://leetcode-cn.com/problems/permutations/)  
- [x] [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)  
