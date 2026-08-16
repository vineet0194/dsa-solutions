/*
Problem: Count Greater on Right Queries
Link: https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
Difficulty: Medium
Approach: Linear Search (BF)
Time Complexity: O(n * queries)
Note:
    
*/

class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        
        vector<int> ans;
        
        for (auto& idx: indices){
            int count = 0;
            
            for (int i=idx+1; i<n; i++){
                if (arr[i] > arr[idx])
                    count++;
            }
            
            ans.emplace_back(count);
        }
        
        return ans;
    }
};