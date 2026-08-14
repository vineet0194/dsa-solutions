/*
Problem: 907. Sum of Subarray Minimums
Link: https://leetcode.com/problems/sum-of-subarray-minimums/description/
Difficulty: Medium
Approach: Monotonic Stacks + Combinatorics
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        vector<int> pse(n);
        for (int i=0; i<n; i++){
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.emplace(i);
        }

        while (!st.empty())
            st.pop();

        vector<int> nse(n);
        for (int i=n-1; i>=0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            nse[i] = st.empty() ? n : st.top();
            st.emplace(i);
        }

        int ans = 0;
        for (int i=0; i<n; i++){
            long long l = i - pse[i];
            long long r = nse[i] - i;

            long long contribution = (1LL * arr[i] * l % MOD) * r % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};