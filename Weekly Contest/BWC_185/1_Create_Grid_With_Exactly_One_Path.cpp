/*
Problem: Q1. Create Grid With Exactly One Path
Link: https://leetcode.com/contest/biweekly-contest-185/problems/create-grid-with-exactly-one-path/
Difficulty: Easy
Approach: Constructive grid construction using a diagonal sweep
Time Complexity: O(mn)
Note:
    
*/

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        if (m==1 || n==1){
            for (int i=0; i<m; i++){
                for (int j=0; j<n; j++){
                    grid[i][j] = '.';
                }
            }
            return grid;
        }

        int i, j;
        bool breakFlag=false;
        for (i=0; i<m; i++){
            for (j=i; j<i+2; j++){
                if (j>=n){
                    breakFlag=true;
                    break;
                }
                grid[i][j] = '.';
            }
            if(breakFlag)
                break;
        }
        
        // rightfill
        if (i==m){
            i--;
            for (; j<n; j++)
                grid[i][j] = '.';
        }

        // downfill
        if (j==n){
            j--;
            i++;
            for (;i<m;i++)
                grid[i][j] = '.';
        }
        
        return grid;
    }
};