/*
Problem: Rearrange String to Avoid Character Pair
Link: https://leetcode.com/contest/biweekly-contest-187/problems/rearrange-string-to-avoid-character-pair/description/
Difficulty: Easy
Approach: Basic Logic
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string yChars = "";
        string xChars = "";
        string others = "";
        
        for (char c : s){
            if (c == y)
                yChars += c;
            else if (c == x)
                xChars += c;
            else
                others += c;
        }
        
        return yChars + others + xChars;
    }
};