/*
Problem: 835. Image Overlap
Link: https://leetcode.com/problems/image-overlap/?envType=daily-question&envId=2026-09-14
Difficulty: Medium
Approach: BF
Time Complexity: O(n^4)
Note:
    
*/

class Solution {
public:
    int countOverlaps(vector<vector<int>>& A, vector<vector<int>>& B, int rowOff, int colOff) {
        int n = A.size();
        int count = 0;
        
        /*
            Uncomment these to see how the matrix is moving. For ease, take example : 
            [[0,1],[0,0]]
            [[0,0],[1,0]]
            
            cout << "\n----------------------------\n";
            cout << "Checking for rowOff = " << rowOff << ", collOff = " << colOff << endl;
        */
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(row+rowOff < 0 || row+rowOff >= n || col+colOff < 0 || col+colOff >= n)
                    continue;
                
                /*
                    cout << "A[" << row << "][" << col << "] = " << A[row][col] << ", ";
                    cout  << "B[" << row+rowOff << "][" << col+colOff << "] = " << B[row+rowOff][col+colOff] << endl;
                */
                
                count += A[row][col]*B[row+rowOff][col+colOff];
            }
        }
        
        /*
            cout << "\n----------------------------\n";
        */
        
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        
        int maxOverlap = 0;
        
        /*
            For ease take this example :
            [[0,1],[0,0]]
            [[0,0],[1,0]]
            
            So, we are basically having rowOffsets from (-n+1) to (n-1). Why ? Read all the comments to know
            For example : n = 2
            rowOff will have values -1, 0, 1
            colOff will have values -1, 0, 1
            
            Based on this rowOff,colOff, we will move B over A starting from "bottom left"
            1) rowOff  = -1, colOff = -1, means B is at bottom left overlapping with A[row][col] and B[row+rowOff][col+colOff]
            i.e. A[row][col] = A[1][1]
            i.e. B[row+rowOff][col+colOff] = B[0][0]
            
            2) For rowOff = -1 , we will have colOff -1, 0, 1 which means we are moving the window B towards right till we cross boundary
            
            Similarly we move ahead with rowOff  = 0, and then 1.....
        */
        
        for(int rowOff = -n+1; rowOff<n; rowOff++) {
            for(int collOff = -n+1; collOff<n; collOff++) {
                maxOverlap = max(maxOverlap, countOverlaps(A, B, rowOff, collOff));
            }
        }
        
        return maxOverlap;
    }
};
