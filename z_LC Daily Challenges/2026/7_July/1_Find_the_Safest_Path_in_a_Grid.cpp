/*
Problem: 2812. Find the Safest Path in a Grid
Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/solutions/8369703/multi-source-bfs-binary-search-clean-and-cylz/?envType=daily-question&envId=2026-07-01
Difficulty: Medium
Approach: Multi-Source BFS + Binary Search
Time Complexity: O(n^2 logn)
Note:
    
*/

class Solution {
public:
    bool isValid(int i, int j, int n){
        if (i < 0 || i >= n || j < 0 || j >= n)
            return false;
        
        return true;
    }

    bool traversalPossible(vector<vector<int>>& d, vector<int>& row, vector<int>& col, int mid){
        if (d[0][0] < mid)
            return false;

        int n = d.size();

        queue<pair<int, int>> q;
        int qsize;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()){
            qsize = q.size();
            for (int k=0; k<qsize; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if (i==n-1 && j==n-1)
                    return true;

                for (int it=0; it<4; it++){
                    int nextI = i + row[it];
                    int nextJ = j + col[it];
                    if (isValid(nextI, nextJ, n) && !visited[nextI][nextJ]){
                        if (d[nextI][nextJ] >= mid){
                            q.push({nextI, nextJ});
                            visited[nextI][nextJ] = 1;
                        }
                    }
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};

        vector<vector<int>> d(n, vector<int>(n, INT_MAX));

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, pair<int,int>>> q;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }

        int max = INT_MIN;
        int qsize;
        while (!q.empty()){
            qsize = q.size();
            for (int k=0; k<qsize; k++){
                int currDist = q.front().first;
                int i = q.front().second.first;
                int j = q.front().second.second;
                q.pop();

                d[i][j] = currDist;

                if (currDist > max)
                    max = currDist;
                
                for (int it=0; it<4; it++){
                    int nextI = i + row[it];
                    int nextJ = j + col[it];
                    if (isValid(nextI, nextJ, n) && !visited[nextI][nextJ]){
                        q.push({currDist+1, {nextI, nextJ}});
                        visited[nextI][nextJ] = 1;
                    }
                }
            }
        }

        int l=0, r=max, ans=0;
        while (l<=r){
            int mid = l+(r-l)/2;
            if (traversalPossible(d, row, col, mid)){
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }

        return ans;
    }
};