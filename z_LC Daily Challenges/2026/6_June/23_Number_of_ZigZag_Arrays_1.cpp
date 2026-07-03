/*
Problem: 3699. Number of ZigZag Arrays I
Link: https://leetcode.com/problems/number-of-zigzag-arrays-i/description/?envType=daily-question&envId=2026-06-23
Difficulty: Hard
Approach: DP
Time Complexity: O(n*m), m=r−l+1, m=>num of distinct values
Note:
    
*/

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m), down(m);

        // length = 2
        for (int v = 0; v < m; v++) {
            up[v] = v;
            down[v] = (m - 1 - v);
        }

        // build lengths 3..n
        for (int len = 3; len <= n; len++) {

            vector<long long> newUp(m), newDown(m);

            // prefix sums of down
            long long pref = 0;
            for (int v = 0; v < m; v++) {
                newUp[v] = pref;
                pref = (pref + down[v]) % MOD;
            }

            // suffix sums of up
            long long suff = 0;
            for (int v = m - 1; v >= 0; v--) {
                newDown[v] = suff;
                suff = (suff + up[v]) % MOD;
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;

        if (n == 1) return m;

        for (int v = 0; v < m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};