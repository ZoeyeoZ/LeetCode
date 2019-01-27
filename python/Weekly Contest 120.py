977. Squares of a Sorted Array
class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        idx = 0
        l = len(A)
        result = [None] * l
        for i in range(l):
            if A[i] >= 0:
                break
        neg = i - 1
        while neg >= 0 or i < l:
            if neg < 0 or i < l and abs(A[i]) <= abs(A[neg]):
                result[idx] = A[i]**2
                i = i + 1
            else:
                result[idx] = A[neg]**2
                neg = neg - 1
            idx = idx + 1
        return result
 

978. Longest Turbulent Subarray
class Solution(object):
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        l = len(A)
        if l == 1:
            return 1
        B = [0] * (l-1)
        for i in range(l-1):
            if A[i] < A[i+1]:
                B[i] = -1
            elif A[i] > A[i+1]:
                B[i] = 1
        res = 1
        cur = abs(B[0]) + 1
        for i in range(l-2):
            if B[i]*B[i+1] < 0:
                cur = cur + 1 
            else:
                if cur > res:
                    res = cur
                cur = abs(B[i+1]) + 1
        if cur > res:
            res = cur
        return res
 

979. Distribute Coins in Binary Tree (*)
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    res = 0
    def distributeCoins(self, root):
        """
        :type root: TreeNode
        :rtype: int
              0
           +1    0
         0->2   0->1
        +3-1    +2-1
        4  0    3  0 
        """
        def dfs(root):
            if root is None:
                return 1
            left = dfs(root.left)
            right = dfs(root.right)
            self.res += abs(left-1) + abs(right-1)
            return root.val + left-1 + right-1 
        dfs(root)
        return self.res


980. Unique Paths III
class Solution(object):
    res = 0
    def uniquePathsIII(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
        1000
        0000
        0002
        4
        [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
        1000
        0000
        002-
        2
        [[0,1],[2,0]]
        01
        20
        0
        
        BRUTE FORCE DFS
        """
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        empty = 1
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1: 
                    x,y = (i, j)
                elif grid[i][j] == 2: 
                    end = (i, j)
                elif grid[i][j] == 0: 
                    empty += 1
        def dfs(x, y, empty):
            if not (0 <= x < n and 0 <= y < m and grid[x][y] >= 0): 
                return
            if (x, y) == end and empty == 0:
                self.res += 1
                return
            grid[x][y] = -2
            dfs(x + 1, y, empty - 1)
            dfs(x - 1, y, empty - 1)
            dfs(x, y + 1, empty - 1)
            dfs(x, y - 1, empty - 1)
            grid[x][y] = 0
        dfs(x,y, empty)
        return self.res
