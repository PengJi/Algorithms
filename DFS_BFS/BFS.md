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

# 双向BFS
[127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)    
[433. 最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)