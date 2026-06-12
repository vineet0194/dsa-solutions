/*
Problem: 200. Number of Islands
Link: https://leetcode.com/problems/number-of-islands/description/
Difficulty: Medium
Approach: BFS
Time Complexity: O(mn)
Note:
    Why O(mn):
        Whenever an unvisited land cell ('1') is found, bfs() is called.

        Inside BFS:

        Each land cell is enqueued at most once.
        Each land cell is dequeued at most once.
        For every dequeued cell, you check exactly 4 neighbors.

        So the work per visited land cell is O(1).
        Across the entire execution, all land cells together are processed only once.
        Therefore, total BFS work over all calls is:
            O(number of cells)=O(mn)

    Iterate through the grid, bfs traverse all non-visited 1 nodes in the grid, count number of times you had 
    to call the bfs => number of islands

    intuition : connected components
*/

class Solution {
public:
    bool isValidAndLand(pair<int,int>& move, vector<vector<char>>& grid){
        int i=move.first;
        int j=move.second;

        int m = grid.size();
        int n = grid[0].size();

        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')
            return false;
        
        return true;
    }
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j]=1;
        int qsize = q.size();
        while (!q.empty()){
            qsize = q.size();
            for (int k=0; k<qsize; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                vector<pair<int, int>> moves={
                    {i-1, j},
                    {i+1, j},
                    {i, j-1},
                    {i, j+1}
                };
                for (auto& move : moves){
                    if (isValidAndLand(move, grid) && !(visited[move.first][move.second])){
                        visited[move.first][move.second] = 1;
                        q.push({move.first, move.second});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, 0));

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1' && !(visited[i][j])){
                    bfs(i, j, grid, visited);
                    islands++;
                }
            }
        }

        return islands;
    }
};