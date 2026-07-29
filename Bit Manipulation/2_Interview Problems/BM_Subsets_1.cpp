/*
Problem: 78. Subsets
Link: https://leetcode.com/problems/subsets/description/
Difficulty: Medium
Approach: Bit Manipulation
Time Complexity: O(n * 2ⁿ)
Note:
    
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i=0; i<(1<<n); i++){
            vector<int> temp;
            for (int j=n-1; j>=0; j--){
                if ((i>>j) & 1)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};