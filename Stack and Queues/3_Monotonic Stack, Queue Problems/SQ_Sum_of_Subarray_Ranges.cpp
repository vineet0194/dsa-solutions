/*
Problem: 2104. Sum of Subarray Ranges
Link: https://leetcode.com/problems/sum-of-subarray-ranges/
Difficulty: Medium
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    🔑 Handling duplicates in monotonic stack:

    We use ASYMMETRIC comparisons so that a subarray with duplicate
    minimum/maximum values is counted exactly ONCE.

    Minimum:
    Left  -> strictly smaller       (<)   => pop >=
    Right -> smaller or equal       (<=)  => pop >

    Maximum:
    Left  -> greater or equal       (>=)  => pop <
    Right -> strictly greater       (>)   => pop <=

    Why?
    Equal elements can both claim the same subarray if we use the
    same comparison on both sides → DOUBLE COUNTING.

    Using strict on one side and non-strict on the other gives
    ownership of the subarray to exactly ONE equal element.

    Easy to remember:

    MIN →  <  | i | <=
    MAX → >=  | i | >

    (Here the symbols describe the element we KEEP, not what we pop.)
*/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        long long ans = 0;
        
        // minimum
        vector<int> pse(n);

        for (int i=0; i<n; i++){
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            
            pse[i] = st.empty() ? -1 : st.top();
            st.emplace(i);
        }

        while (!st.empty())
            st.pop();

        vector<int> nse(n);

        for (int i=n-1; i>=0; i--){
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            
            nse[i] = st.empty() ? n : st.top();
            st.emplace(i);
        }

        while (!st.empty())
            st.pop();
        
        for (int i=0; i<n; i++){
            int l = i - pse[i];
            int r = nse[i] - i;
            ans -= (1LL * nums[i] * l * r);
        }
        
        // maximum

        vector<int> pge(n);

        for (int i=0; i<n; i++){
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            
            pge[i] = st.empty() ? -1 : st.top();
            st.emplace(i);
        }

        while (!st.empty())
            st.pop();

        vector<int> nge(n);

        for (int i=n-1; i>=0; i--){
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            
            nge[i] = st.empty() ? n : st.top();
            st.emplace(i);
        }

        for (int i=0; i<n; i++){
            int l = i - pge[i];
            int r = nge[i] - i;
            ans += (1LL * nums[i] * l * r);
        }

        return ans;
    }
};