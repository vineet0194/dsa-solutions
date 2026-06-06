/*
Problem: 88. Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/description/
Difficulty: Easy
Approach: 2 pointer
Time Complexity: O(m+n)
Note:
    intuition: instead of filling from the front, start filling from the back,
    the greater of the two arrays fills the 0 place in nums1, the rest fit themselves as we iterate further

    if one of the arrays exhaust before the other, simply fill the other array into nums1
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        int put = m+n-1, i=m-1, j=n-1;

        while (i>=0 && j >=0){
            if (nums1[i] >= nums2[j])
                nums1[put--] = nums1[i--];
            else
                nums1[put--] = nums2[j--];
        }
        // if nums1 exhausted, fill w nums2 elems
        while(j>=0)
            nums1[put--] = nums2[j--];
        // if nums2 exhausted, fill w nums1 elems
        while(i>=0)
            nums1[put--] = nums1[i--];
        return;
    }
};