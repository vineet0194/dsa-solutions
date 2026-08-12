/*
Problem: 2958. Length of Longest Subarray With at Most K Frequency
Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12
Difficulty: Medium
Approach: Sliding Window
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        int maxLength = 0;

        int i=0, j=0;
        int n = nums.size();

        while (i<n && j<n){
            freq[nums[j]]++;
            if (freq[nums[j]] > k){
                maxLength = max(maxLength, j-i);
                while (i<j && freq[nums[j]] > k){
                    freq[nums[i]]--;
                    i++;
                }
            }
            j++;
        }

        maxLength = max(maxLength, j-i);

        return maxLength;

    }
};