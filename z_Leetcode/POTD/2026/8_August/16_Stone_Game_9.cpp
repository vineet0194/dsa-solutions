/*
Problem: 2029. Stone Game IX
Link: https://leetcode.com/problems/stone-game-ix/?envType=daily-question&envId=2026-08-16
Difficulty: Medium
Approach: Greedy / Game Theory using modulo 3 counts
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count0, count1, count2, n=stones.size();

        count0 = count1 = count2 = 0;

        for (int i=0; i<n; i++){
            int x = stones[i]%3;
            if (x == 0)
                count0++;
            else if (x == 1)
                count1++;
            else
                count2++;
        }

        if (count0%2 == 0)
            return count1 > 0 && count2 > 0;
        
        return abs(count1-count2) > 2;
    }
};