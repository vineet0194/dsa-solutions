/*
Problem: 169. Majority Element
Link: https://leetcode.com/problems/majority-element/description/
Difficulty: Easy
Approach: Moore's Voting Algorithm
Time Complexity: 
Note:
    
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0], count=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == maj)
                count++;
            else
                count--;
            
            if (count < 0){
                maj = nums[i];
                count=1;
            }
        }
        return maj;
    }
};