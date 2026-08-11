/*
Problem: Postfix to Infix Conversion
Link: https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1
Difficulty: Medium
Approach: Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string> st;
        
        for (auto& ch: exp){
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                st.push({ch});
            else{
                string A = st.top();
                st.pop();
                string B = st.top();
                st.pop();
                st.push("(" + B + ch + A + ")");
            }
        }
        
        return st.top();
    }
};