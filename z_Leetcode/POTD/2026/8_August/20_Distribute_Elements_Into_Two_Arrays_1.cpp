/*
Problem: 3069. Distribute Elements Into Two Arrays I
Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/
Difficulty: Easy
Approach: Linear Iteration
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.emplace_back(nums[0]);
        arr2.emplace_back(nums[1]);
        
        for (int i=2; i<nums.size(); i++){
            if (arr1.back() >= arr2.back())
            arr1.emplace_back(nums[i]);
            
            else
                arr2.emplace_back(nums[i]);
        }
        
        for (auto &num : arr2)
            arr1.emplace_back(num);
            
        return arr1;
    }
};