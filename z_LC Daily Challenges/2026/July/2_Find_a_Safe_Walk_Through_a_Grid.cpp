/*
Problem: 3286. Find a Safe Walk Through a Grid
Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/
Difficulty: Medium
Approach: Best State Tracking + PQ BFS
Time Complexity: O((m⋅n)log(m⋅n))
Note:
    
*/

class Solution {
public:
    bool isValid(int nextI, int nextJ, int m, int n){
        if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n)
            return false;
        return true;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, INT_MIN));

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};

        priority_queue<pair<int, pair<int, int>>> pq;     // {h, {i, j}}
        if (grid[0][0] == 0)
            pq.push({health, {0, 0}});
        else
            pq.push({health-1, {0, 0}});

        while (!pq.empty()){
            int h = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (i==m-1 && j==n-1 && h >= 1){
                return true;
            }

            if (h < best[i][j])
                continue;

            for (int it=0; it<4; it++){
                int nextI = i + row[it];
                int nextJ = j + col[it];
                if (isValid(nextI, nextJ, m, n)){
                    int nextHealth = h;
                    if (grid[nextI][nextJ] == 1)
                        nextHealth = h-1;
                    if (nextHealth > best[nextI][nextJ]){
                        pq.push({nextHealth, {nextI, nextJ}});
                        best[nextI][nextJ] = nextHealth;
                    }
                }
            }
        }

        return false;
    }
};