/*
Problem: Maximum Manhattan Distance After All Moves
Link: https://leetcode.com/contest/weekly-contest-507/problems/maximum-manhattan-distance-after-all-moves/description/
Difficulty: Medium
Approach: Math/Logic
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxDistance(string moves) {
        int x=0, y=0, blanks=0;

        for (auto& c : moves){
            if (c == 'U')
                y--;
            else if (c == 'D')
                y++;
            else if (c == 'L')
                x--;
            else if (c == 'R')
                x++;
            else
                blanks++;
        }

        return abs(x)+abs(y)+blanks;
    }
};