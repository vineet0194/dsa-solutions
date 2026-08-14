/*
Problem: 84. Largest Rectangle in Histogram
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
Difficulty: Hard
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    ! why do you only set right boundary as n and leave the left boundary as -1 ?
    because when you want to do "gap BETWEEN 2 indices" you have to do (r-l-1) right?
    so if right boundary doesnt exists => my right boundary index is actually n (so i can cover heights 0 to n-1)
    and in the same way, my left boundary doesnt exists => my left boundary index becomes -1

    now i need to find the gap/width BETWEEN -1 and n => the entire width of bar
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse(n);
        stack<int> st;

        for (int i=n-1; i>=0; i--){
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()){
            st.pop();
        }

        vector<int> pse(n);

        for (int i=0; i<n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i=0; i<n; i++){
            int currArea = heights[i] * (nse[i] - pse[i] - 1);

            ans = max(ans, currArea);
        }

        return ans;
    }
};