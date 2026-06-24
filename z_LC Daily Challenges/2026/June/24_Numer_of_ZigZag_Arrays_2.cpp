/*
Problem: 3700. Number of ZigZag Arrays II
Link: https://leetcode.com/problems/number-of-zigzag-arrays-ii/description/?envType=daily-question&envId=2026-06-24
Difficulty: Hard
Approach: DP
Time Complexity: O(m^3 logn)    m = r-l+1, m=>num of distinct values
Note:
    
*/

class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    vector<long long> multiplyMatVec(
        const Matrix& A,
        const vector<long long>& v
    ) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0) continue;
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        Matrix T(sz, vector<long long>(sz, 0));

        // U'[v] = sum_{x < v} D[x]
        for (int v = 1; v <= m; v++) {
            for (int x = 1; x < v; x++) {
                T[v - 1][m + x - 1] = 1;
            }
        }

        // D'[v] = sum_{x > v} U[x]
        for (int v = 1; v <= m; v++) {
            for (int x = v + 1; x <= m; x++) {
                T[m + v - 1][x - 1] = 1;
            }
        }

        vector<long long> base(sz, 0);

        // Length 2 state
        for (int v = 1; v <= m; v++) {
            base[v - 1] = v - 1;      // U2[v]
            base[m + v - 1] = m - v;  // D2[v]
        }

        Matrix P = power(T, n - 2);
        vector<long long> finalState = multiplyMatVec(P, base);

        long long ans = 0;
        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};