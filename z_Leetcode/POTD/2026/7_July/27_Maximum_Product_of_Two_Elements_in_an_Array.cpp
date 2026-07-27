/*
Problem: 1464. Maximum Product of Two Elements in an Array
Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2026-07-27
Difficulty: Easy
Approach: Linear Scan
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = -1;
        int smaxi = -1;

        for (int i=0; i<nums.size(); i++){
            if (maxi == -1 || nums[maxi] < nums[i]){
                smaxi = maxi;
                maxi = i;
            }
            else if (smaxi == -1 || nums[smaxi] < nums[i])
                smaxi = i;
        }

        return (nums[maxi]-1) * (nums[smaxi]-1);
    }
};