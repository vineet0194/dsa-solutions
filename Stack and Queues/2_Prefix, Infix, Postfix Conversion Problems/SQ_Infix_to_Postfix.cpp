/*
Problem: Infix to Postfix
Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
Difficulty: Medium
Approach: Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    string infixToPostfix(string& s) {
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
                       (priority[st.top()] == priority[ch] && ch != '^'))) {

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

        return ans;
    }
};
