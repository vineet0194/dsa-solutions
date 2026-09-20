/*
Problem: 3498. Reverse Degree of a String
Link: https://leetcode.com/problems/reverse-degree-of-a-string/?envType=daily-question&envId=2026-09-20
Difficulty: Easy
Approach: Hashing
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int reverseDegree(string s) {
        char index[26];

        for (int i=0; i<26; i++)
            index[i] = 26-i;
        
        int sum = 0;

        for (int i=0; i<s.size(); i++)
            sum += (i+1)*(index[s[i]-'a']);
        

        return sum;
    }
};