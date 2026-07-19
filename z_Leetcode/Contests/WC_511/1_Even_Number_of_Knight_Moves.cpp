/*
Problem: Even Number of Knight Moves©leetcode
Link: https://leetcode.com/contest/weekly-contest-511/problems/even-number-of-knight-moves/description/
Difficulty: Easy
Approach: Logic
Time Complexity: O(1)
Note:
    
*/

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        if ((start[0]+start[1])%2 == (target[0]+target[1])%2)   // same color
            return true;
        else                       // opp color
            return false;
    }
};