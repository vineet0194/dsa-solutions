/*
Problem: Set the rightmost unset bit
Link: https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(1)
Note:
    
*/

class Solution {
  public:
    int setBit(int n) {
        return n|(n+1);
    }
};