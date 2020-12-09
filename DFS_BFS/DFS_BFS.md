# 深度优先搜索

## 递归写法
```python
visited = set() 

def dfs(node, visited):
    if node in visited: # terminator
        # already visited 
        return 

    visited.add(node) 

    # process current node here. 
    ...
    for next_node in node.children(): 
        if next_node not in visited: 
            dfs(next_node, visited)
```

## 非递归写法
```python
def DFS(self, tree): 

    if tree.root is None: 
        return [] 

    visited, stack = [], [tree.root]

    while stack: 
        node = stack.pop() 
        visited.add(node)

        process (node) 
        nodes = generate_related_nodes(node) 
        stack.push(nodes) 

    # other processing work 
    ...
```

# 广度优先搜索
```python
def BFS(graph, start, end):
    visited = set()
    queue = [] 
    queue.append([start]) 

    while queue: 
        node = queue.pop() 
        visited.add(node)

        process(node) 
        nodes = generate_related_nodes(node) 
        queue.push(nodes)

    # other processing work 
    ...
```

# 题目
- [x] [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/#/description)  
- [x] [515. 在每个树行中找最大值](https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/)  
- [x] [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)  
- [x] [126. 单词接龙 II](https://leetcode-cn.com/problems/word-ladder-ii/description/) 
- [x] [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)  
- [x] [529. 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/description/) 


# 双向BFS
- [x] [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)    
- [x] [433. 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)
