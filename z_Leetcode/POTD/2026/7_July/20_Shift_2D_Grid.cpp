/*
Problem: 1260. Shift 2D Grid
Link: https://leetcode.com/problems/shift-2d-grid/description/?envType=daily-question&envId=2026-07-20
Difficulty: Easy
Approach: Simulation
Time Complexity: O(k×m×n) =>  O(m×n)
Note:
    you can do k %= (m*n) but given the constraints, I ignored
*/

class Solution {
public:
    void shiftGrid(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        int last = grid[m-1][n-1];

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                int temp = grid[i][j];
                grid[i][j] = last;
                last = temp;
            }
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        vector<vector<int>> ans = grid;

        for (int i=0; i<k; i++)
            shiftGrid(ans);    

        return ans;
    }
};