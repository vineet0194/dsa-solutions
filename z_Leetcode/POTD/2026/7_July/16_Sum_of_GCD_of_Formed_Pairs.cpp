/*
Problem: 3867. Sum of GCD of Formed Pairs
Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16
Difficulty: Medium
Approach: Prefix Max + GCD Pairing
Time Complexity: O(NlogN)
Note:
    
*/

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx(n);
        vector<int> prefixGcd(n);

        int maxi = nums[0];

        for (int i=0; i<n; i++){
            if (nums[i] > maxi)
                maxi = nums[i];

            mx[i] = maxi;

            prefixGcd[i] = gcd(nums[i], mx[i]);
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());

        int l = 0;
        int r = n-1;

        long long sum=0;
        while (l < r){
            sum += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        
        return sum;
    }
};