/*
Problem: Q2. Minimum Total Cost to Process All Elements©leetcode
Link: https://leetcode.com/contest/weekly-contest-510/problems/minimum-total-cost-to-process-all-elements/description/
Difficulty: Medium
Approach: Greedy
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    const int MOD = 1e9+7;
    const long long MOD_INV_2 = 500000004;

    int minimumCost(vector<int>& nums, int k) {        
        long long ans = 0;
        long long opCount = 1;
        long long currResources = k;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > currResources) {
                long long need = nums[i] - currResources;
                long long temp = (need + k - 1) / k;
                
                long long t1 = temp % MOD;
                long long t2 = (2 * (opCount % MOD) + t1 - 1 + MOD) % MOD;
                
                long long cost = (t1 * t2) % MOD;
                cost = (cost * MOD_INV_2) % MOD;
                
                ans = (ans + cost) % MOD;
                
                currResources += temp * k;
                opCount += temp; 
            }
            currResources -= nums[i];
        }

        return (int) ans;        
    }
};