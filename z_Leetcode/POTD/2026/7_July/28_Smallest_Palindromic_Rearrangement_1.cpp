/*
Problem: 3517. Smallest Palindromic Rearrangement I
Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/?envType=daily-question&envId=2026-07-28
Difficulty: Medium
Approach: Greedy Sorting
Time Complexity: O(nlogn)
Note:
    
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        
        if (n==1)
            return s;
        
        string temp = "";
        for (int i=0; i<n/2; i++)
            temp += s[i];

        sort(temp.begin(), temp.end());

        if (n%2 != 0)
            temp += s[n/2];
        
        for (int i=(n/2)-1; i>=0; i--)
            temp += temp[i];

        return temp;
    }
};