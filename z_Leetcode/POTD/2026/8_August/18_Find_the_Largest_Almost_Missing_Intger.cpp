/*
Problem: 3471. Find the Largest Almost Missing Integer
Link: https://leetcode.com/problems/find-the-largest-almost-missing-integer/?envType=daily-question&envId=2026-08-18
Difficulty: Easy
Approach: Frequency Counting + Boundary Element Observation
Time Complexity: 
    - BF: O(n^2)
    - Optimized: O(n)
Note:
    
*/

// Brute Force, O(n^2)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n)
            return *max_element(nums.begin(), nums.end());
        
        vector<vector<int>> subarrays;

        for (int i=0; i<=n-k; i++){
            vector<int> temp;
            for (int j=i; j<i+k; j++){
                temp.emplace_back(nums[j]);
            }
            subarrays.emplace_back(temp);
        }

        unordered_map<int, int> freq;

        for (auto& subarray: subarrays){
            for (auto& elem: subarray){
                freq[elem]++;
            }
        }

        int maxi = -1;

        for (auto& it: freq){
            if (it.second == 1)
                maxi = max(maxi, it.first);
        }

        return maxi;
    }
};

// Optimal, O(n)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        unordered_map<int, int> freq;

        // Count how many times each value occurs
        for (int x : nums)
            freq[x]++;

        int ans = -1;

        // Only the first and last elements can occur
        // in exactly one length-k subarray.
        if (freq[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};
