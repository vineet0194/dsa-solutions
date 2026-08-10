/*
Problem: 20. Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/description/
Difficulty: Easy
Approach: Stacks
Time Complexity: O(n)   =>      n = s.size();
Note:
    
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto& ch: s){
            if (ch == '(' || ch == '[' || ch == '{')
                st.emplace(ch);
            else{
                if (st.empty())
                    return false;
                if (ch == ')' && st.top() == '(' ||
                    ch == ']' && st.top() == '[' ||
                    ch == '}' && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty();
    }
};