/*
Problem: 628. Maximum Product of Three Numbers
Link: https://leetcode.com/problems/maximum-product-of-three-numbers/?envType=daily-question&envId=2026-07-26
Difficulty: Easy
Approach: Brute Force Enumeration
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi = -1;
        int smaxi = -1;
        int tmaxi = -1;

        for (int i=0; i<nums.size(); i++){
            if (maxi == -1 || nums[i] > nums[maxi]){
                tmaxi = smaxi;
                smaxi = maxi;
                maxi = i;
            }
            else if (smaxi == -1 || nums[i] > nums[smaxi]){
                tmaxi = smaxi;
                smaxi = i;
            }
            else if (tmaxi == -1 || nums[i] > nums[tmaxi])
                tmaxi = i;
        }

        int mini = -1;
        int smini = -1;

        for (int i=0; i<nums.size(); i++){
            if (mini == -1 || nums[i] < nums[mini]){
                smini = mini;
                mini = i;
            }
            else if (smini == -1 || nums[i] < nums[smini])
                smini = i;
        }

        int prod1 = nums[maxi]*nums[smaxi]*nums[tmaxi];
        int prod2 = nums[mini]*nums[smini]*nums[maxi];

        return max(prod1, prod2);
    }
};