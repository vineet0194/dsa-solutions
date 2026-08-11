/*
Problem: Infix To Prefix
Link: https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1
Difficulty: Medium
Approach: Stacks
Time Complexity: O(n)
Note:
    1. reverse the infix
    2. do infix to postfix
    3. reverse the answer
*/

class Solution {
  public:
    string infixToPrefix(string &s) {
        reverse(s.begin(), s.end());
        
        for (auto& ch: s){
            if (ch == '(')
                ch = ')';
            else if (ch == ')')
                ch = '(';
        }
        
        stack<char> st;
        string ans;
        
        unordered_map<char, int> priority;
        priority['^'] = 3;
        priority['*'] = 2;
        priority['/'] = 2;
        priority['+'] = 1;
        priority['-'] = 1;
        priority['('] = 0;
        priority[')'] = 0;
        
        for (auto& ch: s){
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9'){
                ans.push_back(ch);
            }
            else if (ch == '('){
                st.push('(');
            }
            else if (ch == ')'){
                while (!st.empty() && st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else{
                while (!st.empty() && st.top() != '(' &&
                       (priority[st.top()] > priority[ch] ||
                       (priority[st.top()] == priority[ch] && ch == '^'))) {

                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
