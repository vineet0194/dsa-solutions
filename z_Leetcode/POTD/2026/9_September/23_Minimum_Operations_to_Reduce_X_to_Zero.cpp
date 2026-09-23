/*
Problem: 1658. Minimum Operations to Reduce X to Zero
Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/?envType=daily-question&envId=2026-09-23
Difficulty: Medium
Approach: Prefix Sum + Hash Map
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {        
        int n    = nums.size();
        int sum  = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x)
            return -1;
        int restSum  = sum-x;
        int longest  = INT_MIN;
        sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(mp.count(sum-restSum)) {
                longest = max(longest, i-mp[sum-restSum]);
            }
        }
        
        return longest==INT_MIN?-1:n-longest;
    }
};