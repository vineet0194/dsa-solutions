/*
Problem: XOR of a Number Range
Link: https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
Difficulty: Easy
Approach: Bit Manipulation
Time Complexity: O(1)
Note:
    
*/

class Solution {
  public:
    int xorUpto(int n){
        int m = n%4;
        switch(m){
            case 0:
                return n;
            case 1:
                return 1;
            case 2:
                return n+1;
            case 3:
                return 0;
        }
    }
    int findXOR(int l, int r) {
        return xorUpto(l-1) ^ xorUpto(r);
    }
};