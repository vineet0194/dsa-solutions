/*
Problem: 125. Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/
Difficulty: Easy
Approach: Recursion
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool isPal(string& s, int i, int n){
        if (i >= n/2)
            return true;
        if (s[i] != s[n-1-i])
            return false;
        return isPal(s, i+1, n);
    }
    bool isPalindrome(string s) {
        string temp="";
        for (auto& c: s){
            if (isalpha(c) || isdigit(c))
                temp += tolower(c);
        }
        if (temp == " " || temp == "")
            return true;
        return isPal(temp, 0, temp.size());
    }
};