/*
Problem: Next Smaller Element
Link: https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
Difficulty: Medium
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        
        stack<int> st;
        
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        
        return ans;
    }
};