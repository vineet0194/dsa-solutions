/*
Problem: 402. Remove K Digits
Link: https://leetcode.com/problems/remove-k-digits/description/
Difficulty: Medium
Approach: Monotonic Stacks
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if (n == k)
            return "0";

        stack<int> st;
        st.emplace(num[0]-'0');

        // trying to maintain an increasing order (monotonic)
        for (int i=1; i<n; i++){
            while (k>0 && !st.empty() && num[i]-'0' < st.top()){
                k--;
                st.pop();
            }

            st.emplace(num[i]-'0');
        }

        // if k>0 after the loop, remove digits from the end
        // as these will be the largest digits (since we have inc order)
        while (k>0){
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()){
            ans.push_back(st.top() + '0');
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        int i=0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;;
    }
};