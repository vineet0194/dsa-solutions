/*
Problem: 1020. Number of Enclaves
Link: https://leetcode.com/problems/number-of-enclaves/
Difficulty: Medium
Approach: DFS
Time Complexity: O(m*n)
Note:

Cost: O(m × n)

DFS
Every land cell connected to a boundary is visited at most once.

Cost: O(m × n)

Counting enclaves
Another full grid traversal.

Cost: O(m × n)

Overall:

O(mn)+O(mn)+O(mn)=O(mn)

    why is DFS added to boundary traversals and not multiplied?

Because the DFS calls across different boundary cells are not independent work.

When analyzing nested loops, we multiply only when the inner work runs fully for every outer iteration.

Suppose there are B boundary cells.

A naive analysis might say:

O(B)×O(mn)

but that's incorrect because each DFS does not traverse the entire grid.

The visited array guarantees that once a cell is visited, no future DFS visits it again.

*/

class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1 || visited[i][j])
            return false;
        
        return true;
    }

    void dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& grid){
        visited[i][j]=1;
        vector<pair<int, int>> neighbours={
            {i-1, j},
            {i+1, j},
            {i, j-1},
            {i, j+1}
        };
        for (auto& neigh : neighbours){
            int nextI = neigh.first;
            int nextJ = neigh.second;
            if (isValid(nextI, nextJ, visited, grid)){
                dfs(nextI, nextJ, visited, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if ((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1 && !visited[i][j]){  // if (unvisited boundary with 1)
                    dfs(i, j, visited, grid);
                }
            }
        }

        int ans=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==1 && !visited[i][j])
                    ans++;
            }
        }

        return ans;
    }
};