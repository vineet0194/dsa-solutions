/*
Problem: 130. Surrounded Regions
Link: https://leetcode.com/problems/surrounded-regions/description/
Difficulty: Medium
Approach: Multi-source BFS
Time Complexity: O(mn)
Note:
    
*/

class Solution {
public:
    bool isValid(pair<int, int>& neigh, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        
        if (neigh.first < 0 || neigh.first >= m || neigh.second < 0 || neigh.second >= n)
            return false;
        
        return true;
    }

    void implementBFS(queue<pair<int, int>>& q, vector<vector<char>>& board, vector<vector<int>>& visited){
        int qsize;
        while (!q.empty()){
            qsize = q.size();
            for (int i=0; i<qsize; i++){
                int currI = q.front().first;
                int currJ = q.front().second;
                q.pop();
                vector<pair<int, int>> neighbours={
                    {currI-1, currJ},
                    {currI+1, currJ},
                    {currI, currJ-1},
                    {currI, currJ+1}
                };
                for (auto& neigh : neighbours){
                    if (isValid(neigh, board) && !visited[neigh.first][neigh.second]){
                        if (board[neigh.first][neigh.second] == 'O'){
                            visited[neigh.first][neigh.second] = 2;
                            q.push({neigh.first, neigh.second});
                        }
                        else
                            visited[neigh.first][neigh.second] = 1;
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j] == 'O' &&  (i == 0 || i == m-1 || j ==0 || j == n-1)){
                    q.push({i, j});
                    visited[i][j] = 2;
                }
            }
        }

        implementBFS(q, board, visited);

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j] == 'O' && visited[i][j]!=2)
                    board[i][j] = 'X';
            }
        }

        return;
    }
};