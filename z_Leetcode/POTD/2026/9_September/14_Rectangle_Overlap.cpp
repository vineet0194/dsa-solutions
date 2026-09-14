/*
Problem: 836. Rectangle Overlap
Link: https://leetcode.com/problems/rectangle-overlap/description/?envType=daily-question&envId=2026-09-14
Difficulty: Easy
Approach: Logic
Time Complexity: O(1)
Note:
    
*/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];

        if (x3 >= x2 || x1 >= x4 || y3 >= y2 || y1 >= y4)
            return false;
        
        return true;
    }
};