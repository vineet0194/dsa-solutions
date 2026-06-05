/*
Problem: 1. Two Sum
Link: https://leetcode.com/problems/two-sum/description/
Difficulty: Easy
Approach: Hashing (searching for compliment)
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;   // <number, index>
        vector<int> ans;

        for (int i=0; i<nums.size(); i++){
            int com = target-nums[i];
            auto it = umap.find(com);
            if (it != umap.end()){
                if (it->second > i)
                    ans = {i, it->second};
                else
                    ans = {it->second, i};
            }
            umap.insert({nums[i], i});
        }

        return ans;
    }
};