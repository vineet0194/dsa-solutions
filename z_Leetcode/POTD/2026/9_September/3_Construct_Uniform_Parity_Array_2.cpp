/*
Problem: 3876. Construct Uniform Parity Array II
Link: https://leetcode.com/problems/construct-uniform-parity-array-ii/description/?envType=daily-question&envId=2026-09-03
Difficulty: Medium
Approach: Logic
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int mini = nums1[0];

        for (int i=0; i<n; i++){
            if (nums1[i] < mini)
                mini = nums1[i];
        }

        // if mini is odd, we can make all odd as (O-E = E-O = Odd)
        if (mini%2 == 1)
            return true;

        for (int i=0; i<n; i++){
            if (nums1[i]%2 == 1)
                return false;
        }

        return true;
    }
};