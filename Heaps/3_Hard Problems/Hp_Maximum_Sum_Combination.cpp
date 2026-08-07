/*
Problem: Maximum Sum Combination
Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
Difficulty: Medium
Approach: Heaps
Time Complexity: O(nlogn + n² + klogk)
Note:
    
*/

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        priority_queue<vector<int>> pq;
        
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        
        pq.push({a[0]+b[0], 0, 0});
        
        vector<int> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        for (int it=0; it<k; it++){
            
            int curr = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            
            ans.emplace_back(curr);
            
            if (i+1 < n && !visited[i + 1][j]){
                visited[i+1][j] = true;
                pq.push({a[i+1] + b[j], i+1, j});
            }
            
            if (j+1 < n && !visited[i][j + 1]){
                visited[i][j+1] = true;
                pq.push({a[i] + b[j+1], i, j+1});
            }
        }

        return ans;
    }
};