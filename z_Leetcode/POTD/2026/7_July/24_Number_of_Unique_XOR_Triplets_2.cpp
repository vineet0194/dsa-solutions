/*
Problem: 3514. Number of Unique XOR Triplets II
Link: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/?envType=daily-question&envId=2026-07-24
Difficulty: Medium
Approach: Bit Manipulation
Time Complexity: O(n^2)
Note:
    
*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> set;

        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                set.insert(nums[i]^nums[j]);
            }
        }

        unordered_set<int> ans;

        for (auto& item: set){
            for (auto& num: nums)
                ans.insert(item^num);
        }
        
        return ans.size();
    }
};