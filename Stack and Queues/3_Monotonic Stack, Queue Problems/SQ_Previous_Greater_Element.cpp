/*
Problem: Previous Greater Element
Link: https://www.geeksforgeeks.org/problems/previous-greater-element/1
Difficulty: Medium
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> st;
        
        vector<int> pge(n);
        
        for (int i=0; i<n; i++){
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
            
            pge[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        
        return pge;
    }
};