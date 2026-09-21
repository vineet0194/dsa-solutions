/*
Problem: 3524. Find X Value of Array I
Link: https://leetcode.com/problems/find-x-value-of-array-i/?envType=daily-question&envId=2026-09-22
Difficulty: Medium
Approach: DP
Time Complexity: O(n × k)
Note:
    
*/

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevCount(k, 0);

        for(int i = 0; i < n; i++) {

            //index i par end hone waale all subarrays
            vector<long long> currCount(k, 0);

            int currElementRemainder = nums[i]%k;
            currCount[currElementRemainder]++;

            for(int oldRem = 0; oldRem <= k-1; oldRem++) {
                int newRemain = ((long long)oldRem * nums[i] % k) % k;

                currCount[newRemain] += prevCount[oldRem];
            }

            prevCount = move(currCount);

            for(int x = 0; x <= k-1; x++) {
                result[x] += prevCount[x];
            }
        }

        return result;
    }
};