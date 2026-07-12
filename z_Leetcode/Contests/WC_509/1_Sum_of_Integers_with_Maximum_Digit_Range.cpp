/*
Problem: Sum of Integers with Maximum Digit Range©leetcode
Link: https://leetcode.com/contest/weekly-contest-509/problems/sum-of-integers-with-maximum-digit-range/description/
Difficulty: Easy
Approach: Two pass + Hashing
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int range(int num){
        int maxi=INT_MIN, mini=INT_MAX;
        while (num > 0){
            int temp = num%10;
            
            if (temp > maxi)
                maxi = temp;
            if (temp < mini)
                mini = temp;

            num /= 10;
        }
        return maxi-mini;
    }
    
    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); i++){
            int temp = range(nums[i]);
            mp[nums[i]] = temp;
            if (temp > maxRange)
                maxRange = temp;
        }

        int sum=0;
        for (int i=0; i<nums.size(); i++){
            if (mp[nums[i]] == maxRange)
                sum+=nums[i];
        }

        return sum;
    }
};