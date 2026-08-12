/*
Problem: 503. Next Greater Element II
Link: https://leetcode.com/problems/next-greater-element-ii/description/
Difficulty: Medium
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        
        int n = nums.size();
        vector<int> nge(n);

        for (int i=n-2; i>=0; i--)
            st.emplace(nums[i]);

        for (int i=n-1; i>=0; i--){
            while (!st.empty() && st.top() <= nums[i])
                st.pop();
            
            nge[i] = st.empty() ? -1 : st.top();
            st.emplace(nums[i]);
        }

        return nge;
    }
};