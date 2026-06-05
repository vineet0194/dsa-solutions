/*
Problem: 1752. Check if Array is Sorted and Rotated
Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
Difficulty: Easy
Approach: Linear Search, counting the falls
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int fallCount=0;
        for (int i=1; i<nums.size(); i++){
            if (i<nums.size() && nums[i]<nums[i-1])
                fallCount++;
        }
        cout << fallCount;

        if (fallCount == 0)
            return true;
        else if (fallCount > 1)
            return false;
        else if (nums[0]<nums[nums.size()-1])
            return false;
        
        return true;
    }
};