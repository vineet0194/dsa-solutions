/*
Problem: Prefix to Infix Conversion
Link: https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1
Difficulty: Medium
Approach: Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    string preToInfix(string &s) {
        reverse(s.begin(), s.end());
        stack<string> st;
        
        for (auto& ch: s){
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                st.push({ch});
            else{
                string A = st.top();
                st.pop();
                string B = st.top();
                st.pop();
                st.push('(' + A + ch + B + ')');
            }
        }
        
        return st.top();
    }
};