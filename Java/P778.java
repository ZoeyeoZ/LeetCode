package com.company;

public class P778 {
    /*
    https://discuss.leetcode.com/topic/120455/java-binary-search-dfs-o-n-2logn-12ms
    The idea is find the feasible path when time = t.
    Since time can vary from `grid[0][0]` to `n*n-1`,  we use `Binary Search` for possible time -> O(log g^2) = `O(log n)`
    And every time, we need to verify whether there exists a path from grid[0][0] to grid[n-1][n-1], we use `DFS` to verify the feasibility -> O(log k^2) -> `O(log n^2)`
    So the total time complexity is `O(n^2logn)`
    */
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int l = grid[0][0], r = n * n - 1;
        while (l < r){
            int m = l + ((r - l ) >>> 1);
            if (isValid(grid, m))
                r = m;
            else
                l = m +1;
        }
        return l;
    }

    public boolean isValid(int[][] grid, int t){
        int n = grid.length;
        int[][] visited = new int[n][n];
        int[][] moves = {{-1,0},{1,0},{0,-1},{0,1}};
        return dfs(grid, visited, moves, t, 0, 0, n);
    }

    public boolean dfs(int[][] grid, int[][] visited, int[][] moves, int t, int x, int y, int n){
        if (x == n-1 && y == n-1)
            return true;
        visited[x][y] = 1;
        for (int[] move : moves){
            int xx = x + move[0];
            int yy = y + move[1];
            if (xx >=  0 && xx < n && yy >= 0 && yy < n
                && visited[xx][yy] == 0 && grid[xx][yy] <= t)
                if (dfs(grid, visited, moves, t, xx, yy, n))
                    return true;
        }
        return false;
    }
}
/*
Others: DP + DFS
final static int[][] steps = {{0,1},{0,-1}, {1,0},{-1,0}};
public int swimInWater(int[][] grid) {
    int n = grid.length;
    int[][] max = new int[n][n];
    for(int[] line : max)
        Arrays.fill(line, Integer.MAX_VALUE);
    dfs(grid, max, 0, 0, grid[0][0]);
    return max[n-1][n-1];
}

private void dfs(int[][] grid, int[][] max, int x, int y, int cur) {
    int n = grid.length;
    if (x < 0 || x >= n || y < 0 || y >= n || Math.max(cur, grid[x][y]) >= max[x][y])
        return;
    max[x][y] = Math.max(cur, grid[x][y]);
    for(int[] s : steps) {
        dfs(grid, max, x + s[0], y + s[1], max[x][y]);
    }
}
*/
