/*
Problem: 3754. Concatenate Non-Zero Digits and Multiply by Sum I
Link: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/description/?envType=daily-question&envId=2026-07-07
Difficulty: Digit Extraction and Stack Traversal
Approach: Linear
Time Complexity: O(d)
Note:
    
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        stack<int> st;
        long long sum=0;
        while (n > 0){
            int digit = n%10;
            sum += digit;
            if (digit != 0)
                st.push(digit);
            n /= 10;
        }
        if (st.empty())
            return 0;
        
        long long x = 0;
        while (!st.empty()){
            x = x*10 + st.top();
            st.pop();
        }

        return x*sum;
    }
};