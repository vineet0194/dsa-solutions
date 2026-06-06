/*
Problem: 54. Spiral Matrix
Link: https://leetcode.com/problems/spiral-matrix/description/
Difficulty: Medium
Approach: Matrix path simulation
Time Complexity: O(mn)
Note:
    maintain srow, erow, scol and ecol
    make sure not to print elements twice by managing the range in for loop
    if only 1 row exists, print top and discard bottom
    if only 1 col exists, print left and discard right
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> arr;
        int srow=0, erow=m-1, scol=0, ecol=n-1, elems=0;
        while (elems<m*n){
            // top print
            for (int i=scol; i<=ecol; i++){
                arr.emplace_back(matrix[srow][i]);
                elems++;
            }
            // right print
            for (int j=srow+1; j<=erow; j++){
                arr.emplace_back(matrix[j][ecol]);
                elems++;
            }
            // bottom print
            for (int k=ecol-1; k>=scol; k--){
                if (srow == erow)               // 1 row => discard bottom
                    break;
                arr.emplace_back(matrix[erow][k]);
                elems++;
            }
            // left print
            for (int l=erow-1; l>=srow+1; l--){
                if (scol == ecol)               // 1 col => discard right
                    break;
                arr.emplace_back(matrix[l][scol]);
                elems++;
            }
            srow++; ecol--; erow--; scol++;
        }

        return arr;
    }
};