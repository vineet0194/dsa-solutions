/*
Problem: 3014. Minimum Number of Pushes to Type Word I
Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/?envType=daily-question&envId=2026-07-30
Difficulty: Easy
Approach: Greedy Counting
Time Complexity: O(n/8) => O(n), n is at max 26 => O(1)
Note:
    
*/

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8)
            return n;
        
        int count = 8;
        n -= 8;

        int i=2;
        while (n > 8){
            count += i*8;
            n -= 8;
            i++;
        }

        count += i*n;

        return count;
    }
};