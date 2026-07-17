/*
Problem: 1048. Longest String Chain
Link: https://leetcode.com/problems/longest-string-chain/
Difficulty: Medium
Approach: DP
Time Complexity: my solution - O(n^2 x L)     L => length of longest string
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n^2, n)

class Solution {
public:
    int n;
    bool takeable(string& last, string& curr){
        if (last.size() != curr.size()+1)
            return false;

        int i=0, j=0;
        int count=0;
        while (i < last.size() && j < curr.size()){
            if (last[i] != curr[j]){
                count++;
                if (count > 1)
                    return false;
                i++;
                continue;
            }
            
            i++;
            j++;
        }
        return true;
    }
    int solve(int i, int last, vector<string>& words, vector<vector<int>>& dp){
        if (i==n)
            return dp[i][last+1] = 0;

        if (dp[i][last+1] != -1)
            return dp[i][last+1];

        int take = 0;
        if (last == -1 || takeable(words[last], words[i]))
                take = 1 + solve(i+1, i, words, dp);

        int skip = solve(i+1, last, words, dp);

        return dp[i][last+1] = max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        this->n = words.size();

        // sort by size
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, -1, words, dp);
    }
};

// DP Tabulation, Space Complexity: O(n^2)

class Solution {
public:
    bool takeable(string& last, string& curr){
        if (last.size() != curr.size()+1)
            return false;

        int i=0, j=0;
        int count=0;
        while (i < last.size() && j < curr.size()){
            if (last[i] != curr[j]){
                count++;
                if (count > 1)
                    return false;
                i++;
                continue;
            }
            
            i++;
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // sort by size
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int last=-1; last<n; last++)
            dp[n][last+1] = 0;
        
        for (int i=n-1; i>=0; i--){
            for (int last=n-1; last>=-1; last--){
                int take = 0;
                if (last == -1 || takeable(words[last], words[i]))
                        take = 1 + dp[i+1][i+1];

                int skip = dp[i+1][last+1];

                dp[i][last+1] = max(take, skip);
            }
        }

        return dp[0][0];    // dp[0][-1+1]
    }
};

// Space Optimization, Space Complexity: O(n)

class Solution {
public:
    bool takeable(string& last, string& curr){
        if (last.size() != curr.size()+1)
            return false;

        int i=0, j=0;
        int count=0;
        while (i < last.size() && j < curr.size()){
            if (last[i] != curr[j]){
                count++;
                if (count > 1)
                    return false;
                i++;
                continue;
            }
            
            i++;
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // sort by size
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });

        vector<int> prev(n+1, -1);
        vector<int> curr(n+1, -1);

        for (int last=-1; last<n; last++)
            prev[last+1] = 0;
        
        for (int i=n-1; i>=0; i--){
            for (int last=n-1; last>=-1; last--){
                int take = 0;
                if (last == -1 || takeable(words[last], words[i]))
                        take = 1 + prev[i+1];

                int skip = prev[last+1];

                curr[last+1] = max(take, skip);
            }
            prev = curr;
        }

        return prev[0];    // dp[0][-1+1]
    }
};