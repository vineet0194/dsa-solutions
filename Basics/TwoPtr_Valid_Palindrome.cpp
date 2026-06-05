/*
Problem: 125. Valid Palindrome
Link: https://leetcode.com/problems/valid-palindrome/
Difficulty: Easy
Approach: Two pointer
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for (auto c: s){
            if (isalpha(c) || isdigit(c))
                temp += tolower(c);
        }
        int l=0, r=temp.size()-1;
        while (l<r){
            if (temp[l]==temp[r]){
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};