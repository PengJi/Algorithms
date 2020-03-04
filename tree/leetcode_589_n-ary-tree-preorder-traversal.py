"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution(object):
    # 利用栈
    # 时间复杂度：O(n)
    # 空间复杂度：O(n)
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root is None:  # 此处如果使用 not root，则执行时间会下降
            return []

        stack, output = [root, ], []
        while stack:
            root = stack.pop()
            output.append(root.val)
            stack.extend(root.children[::-1])

        return output