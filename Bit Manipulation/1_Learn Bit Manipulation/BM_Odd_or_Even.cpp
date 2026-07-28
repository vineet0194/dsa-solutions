/*
Problem: Odd or Even
Link: https://www.geeksforgeeks.org/problems/odd-or-even3618/1
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(1)
Note:
    
*/

class Solution {
  public:
    bool isEven(int n) {
        return !(n&1);
    }
};