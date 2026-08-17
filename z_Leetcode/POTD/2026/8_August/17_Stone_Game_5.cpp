/*
Problem: 1563. Stone Game V
Link: https://leetcode.com/problems/stone-game-v/?envType=daily-question&envId=2026-08-17
Difficulty: Hard
Approach: DP
Time Complexity: O(n^3)
Note:
    
*/

class Solution {
public:
    int t[501][501];
    int solve(int l, int r, vector<int>& cumSum) {
        if(l >= r) {
            return 0; //Zero score. No further division possible
        }

        if(t[l][r] != -1) {
            return t[l][r];
        }

        int score = 0;
        for(int mid = l; mid <= r-1; mid++) {
            int leftSum  = cumSum[mid] - (l-1 >= 0 ? cumSum[l-1] : 0); //[l..mid]
            int rightSum = cumSum[r] - cumSum[mid]; //mid+1, r

            if(leftSum < rightSum) {
                score = max(score, leftSum + solve(l, mid, cumSum));
            } else if(leftSum > rightSum) {
                score = max(score, rightSum + solve(mid+1, r, cumSum));
            } else {
                score = max({score, leftSum + solve(l, mid, cumSum), rightSum + solve(mid+1, r, cumSum)});
            }
        }

        return t[l][r] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = stoneValue[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i-1] + stoneValue[i];
        }

        memset(t, -1, sizeof(t));
        return solve(0, n-1, cumSum);
    }
};