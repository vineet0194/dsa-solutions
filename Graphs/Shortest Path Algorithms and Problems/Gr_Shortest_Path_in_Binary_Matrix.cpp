/*
Problem: 1091. Shortest Path in Binary Matrix
Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
Difficulty: Medium
Approach: BFS
Time Complexity: O(N^2)
Note:
    8D movements:
        (i-1, j-1)   (i-1, j)   (i-1, j+1)

        (i,   j-1)       X      (i,   j+1)

        (i+1, j-1)   (i+1, j)   (i+1, j+1)

    at the worst case, the matrix would be full of 0s (all nodes accessible)
    so at max n^2 nodes will be accessible, we do 8 checks per cell => O(N^2)*8 => O(N^2)
*/

class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        if (i<0 || i>=n || j<0 || j>=n || grid[i][j]==1)
            return false;
        
        return true;
    }

    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int n = grid.size();

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {i, j}});
        visited[i][j] = 1;

        int qsize;
        vector<int> rows = {-1, 0, 1};
        vector<int> cols = {-1, 0, 1};

        while(!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int currI = q.front().second.first;
                int currJ = q.front().second.second;
                int currLength = q.front().first;
                q.pop();
                if (currI == n-1 && currJ == n-1)
                    return currLength;
                for (auto& r : rows){
                    for (auto& c : cols){
                        if (r==0 && c==0)       // will skip (next = curr) creation
                            continue;
                        int nextI = currI+r;
                        int nextJ = currJ+c;
                        if (isValid(nextI, nextJ, grid) && !visited[nextI][nextJ]){
                            q.push({currLength+1, {nextI, nextJ}});
                            visited[nextI][nextJ] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        
        int n = grid.size();
        if (n == 1){                // 1x1 matrix and we already know elem is not 1
            return 1;
        }
        

        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        
        int length = bfs(0, 0, grid, visited);

        return length;
    }
};