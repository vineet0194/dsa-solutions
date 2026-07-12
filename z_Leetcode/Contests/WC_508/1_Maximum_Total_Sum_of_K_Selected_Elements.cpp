/*
Problem: Maximum Total Sum of K Selected Elements©leetcode
Link: https://leetcode.com/contest/weekly-contest-508/problems/maximum-total-sum-of-k-selected-elements/
Difficulty: Medium
Approach: Greedy
Time Complexity: O(nlogn)
Note:
    
*/

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());

        long long ans=0;
        for (int i=0; i<k; i++){
            long long product = 1LL * nums[i] * mul;
            if (product > nums[i]){
                ans += product;
                mul--;
            }
            else
                ans += nums[i];
        }

        return ans;
    }
};