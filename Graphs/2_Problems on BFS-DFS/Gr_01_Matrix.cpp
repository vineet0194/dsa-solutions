/*
Problem: 542. 01 Matrix
Link: https://leetcode.com/problems/01-matrix/description/
Difficulty: Medium
Approach: Multi-source BFS
Time Complexity: O(mn)
Note:
    ! for unweighted graph, BFS guarantees anytime you visit a node for the first time, that's it's shortest dist from source
*/

class Solution {
public:
    bool isValid(pair<int, int>& neigh, vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        
        if (neigh.first < 0 || neigh.first >= m || neigh.second < 0 || neigh.second >= n)
            return false;
        
        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, pair<int, int>>> q;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 0){
                    q.push({0, {i, j}});
                    visited[i][j] = true;
                    ans[i][j] = 0;
                }
            }
        }

        int qsize = 0;
        while (!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int currDist = q.front().first;
                int currI = q.front().second.first;
                int currJ = q.front().second.second;
                q.pop();
                if (mat[currI][currJ] == 0)  // 0 found
                    currDist = 0;
                else{
                    ans[currI][currJ] = min(ans[currI][currJ], currDist);
                }
                vector<pair<int, int>> neighbours={
                    {currI-1, currJ},
                    {currI+1, currJ},
                    {currI, currJ+1},
                    {currI, currJ-1}
                };
                for (auto& neigh : neighbours){
                    if (isValid(neigh, mat) && !visited[neigh.first][neigh.second]){
                        q.push({currDist+1, {neigh.first, neigh.second}});
                        visited[neigh.first][neigh.second] = 1;
                    }
                }
            }
        }

        return ans;
    }
};