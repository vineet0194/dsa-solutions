/*
Problem: 994. Rotting Oranges
Link: https://leetcode.com/problems/rotting-oranges/
Difficulty: Medium
Approach: Multi-source BFS
Time Complexity: O(mn)
Note:
    ! Multi-source BFS !
    Whenever multiple sources spread simultaneously (rotten oranges, fire spread, infection spread, nearest distance from multiple cells), think Multi-Source BFS instead of running BFS from each source separately.

    Idea: Instead of starting BFS from one node, start from multiple source nodes simultaneously. All sources are treated as distance 0 (or here, time 0).

    here, we use a queue where we pass 3 elements for a node -> i,j (row/col values) and t => time at which this was passed
    answer = maximum timestamp processed in BFS
    therefore, at every node => we do => maxTm = max(maxTm, currTm);

    we do a correctness check (all fresh oranges were reachable and rotted)
    iff freshBefore = freshRotten
    if freshRotten != freshBefore then at least one fresh orange was unreachable
    else
        return maxTm        =>      min possible time to rot all oranges
*/

class Solution {
public:
    bool isValidAndFresh(vector<int>& dirxn, vector<vector<int>>& grid){
        int i = dirxn[0];
        int j = dirxn[1];

        int m = grid.size();
        int n = grid[0].size();

        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
            return false;

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n));

        int freshBefore=0, freshRotten=0, tm=0;

        queue<vector<int>> q;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==2){
                    q.push({i, j, tm});
                    visited[i][j] = 2;
                }
                else if (grid[i][j] == 1)
                    freshBefore++;
            }
        }

        int qsize = q.size();
        while (!q.empty()){
            qsize = q.size();
            for (int k=0; k<qsize; k++){
                int i = (q.front())[0];
                int j = (q.front())[1];
                int t = (q.front())[2];
                tm = max(tm, t);
                q.pop();
                vector<vector<int>> dirxns = {
                    {i+1, j, t+1},
                    {i-1, j, t+1},
                    {i, j-1, t+1},
                    {i, j+1, t+1}
                };
                for (auto& dirxn : dirxns){
                    // if (valid && fresh && notVisited)
                    if (isValidAndFresh(dirxn, grid) && !(visited[dirxn[0]][dirxn[1]]==2)){
                        q.push(dirxn);
                        visited[dirxn[0]][dirxn[1]] = 2;
                        freshRotten++;
                    }
                }
            }
        }

        if (freshRotten != freshBefore)
            return -1;
        
        return tm;
    }
};