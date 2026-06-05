/*
Problem: 189. Rotate Array
Link: https://leetcode.com/problems/rotate-array/
Difficulty: Medium
Approach: Flipping Algorithm
Time Complexity: O(n)
Note:
    STL Functions follow [) type of ranges
    
    Flipping Algorithm
    to left rotate:     Rotate First Half   (0   , 0+d)
                        Rotate Second Half  (0+d , 0+n)
                        Rotate Entire Arr   (0   , 0+n)

    to right rotate:    Rotate Entire Arr   (0   , 0+n)
                        Rotate First Half   (0   , 0+d)
                        Rotate Second Half  (0+d , 0+n)
        or alternatively,
                        k = k%n
                        k = (n-k)
                        Now, follow left rotate algo
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.begin()+n);
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.begin()+n);

        return;
    }
};