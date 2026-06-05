/*
Problem: 74. Search a 2D Matrix
Link: https://leetcode.com/problems/search-a-2d-matrix/description/
Difficulty: Medium
Approach: BS over col then BS over row
Time Complexity: O(mn)
Note:
    
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l=0, h=m-1, row=0;;
        while (l<=h){
            int mid = l+(h-l)/2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n-1]){
                row=mid;
                break;
            }
            else if (matrix[mid][n-1] < target)
                l=mid+1;
            else if (matrix[mid][0] > target)
                h=mid-1;
        }
        l=0, h=n-1;
        while (l<=h){
            int mid = l+(h-l)/2;
            if (matrix[row][mid]==target)
                return true;
            else if (matrix[row][mid] < target)
                l=mid+1;
            else
                h=mid-1;
        }
        return false;
    }
};