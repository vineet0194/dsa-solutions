/*
Problem: Valid Subarrays With Matching Sum Digits I©leetcode
Link: https://leetcode.com/contest/weekly-contest-507/problems/valid-subarrays-with-matching-sum-digits-i/description/
Difficulty: Medium
Approach: Optimized subarray sum
Time Complexity: O(n^2)
Note:
    sum is memoized for the current value of l, we only add nums[r] at each iteration r
*/

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0;
        for (int l=0; l<nums.size(); l++){
            long long sum=0;
            for (int r=l; r<nums.size(); r++){
                sum += nums[r];
                long long last = sum%10;
                long long first = sum;
                while (first >= 10){
                    first /= 10;
                }
                if (first == x && last == x)
                    ans++;
            }
        }
        return ans;
    }
};