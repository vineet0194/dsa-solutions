/*
Problem: Merge k Sorted Arrays
Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
Difficulty: Medium
Approach: Min Heap
Time Complexity:    K = number of sorted arrays (mat.size())
                    N = total number of elements across all arrays
Note:
    
*/

// Brute Force => O(NlogN)
// size of heap becomes N, so insertion and deletions in heap are O(logN)
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i=0; i<mat.size(); i++){
            for (int j=0; j<mat[i].size(); j++)
                pq.push(mat[i][j]);
        }
        
        vector<int> ans;
        
        while (!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};

// Optimal => O(Nlogk)
// size of heap stays atmost K, so insertion and deletions in heap are O(logK) instead of O(logN)
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int n = mat.size();
        for (int i=0; i<n; i++)
            pq.push({mat[i][0], i, 0});
        
        vector<int> ans;
        while (!pq.empty()){
            int elem = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            
            ans.push_back(elem);
            
            if (j+1 < mat[i].size())
                pq.push({mat[i][j+1], i, j+1});
        }
        
        return ans;
    }
};