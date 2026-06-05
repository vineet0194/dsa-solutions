/*
Problem: 73. Set Matrix
Link: https://leetcode.com/problems/set-matrix-zeroes/
Difficulty: Medium
Approach: Hashing
Time Complexity: O(m*n)
Note:
    first solution is inplace, Space Complexity of O(1)
    second uses O(m*n) extra space
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false, firstColZero = false;

        int m=matrix.size(), n=matrix[0].size();
        for (int i=0; i<n; i++){
            if (matrix[0][i] == 0)
                firstRowZero = true;
        }
        for (int i=0; i<m; i++){
            if (matrix[i][0] == 0)
                firstColZero = true;
        }

        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        // if first colcell = 0
        for (int i=1; i<m; i++){
            if (matrix[i][0] == 0){
                for (int j=1; j<n; j++){
                    matrix[i][j]=0;
                }
            }
        }

        // if first rowcell = 0
        for (int i=1; i<n; i++){
            if (matrix[0][i] == 0){
                for (int j=1; j<m; j++){
                    matrix[j][i]=0;
                }
            }
        }

        if (firstRowZero){
            for (int i=0; i<n; i++)
                matrix[0][i]=0;
        }
        if (firstColZero){
            for (int i=0; i<m; i++)
                matrix[i][0]=0;
        }

        return;
    }
};