/*
Problem: Count Subsets with Sum K
Link: https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM
Difficulty: Medium
Approach: DP
Time Complexity: O(n*k)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*k + n)

const int MOD = 1e9 + 7;

int solve(int i, int crsum, int k, vector<int>& arr, vector<vector<int>>& dp){
	if (i == arr.size()){
		if (crsum == k)
			return 1;
		else
			return 0;
	}

	if (dp[i][crsum] != -1)
		return dp[i][crsum];

	int take = 0, notTake = 0;
	if (crsum + arr[i] <= k)
		take = solve(i+1, crsum+arr[i], k, arr, dp);
	notTake = solve(i+1, crsum, k, arr, dp);

	return dp[i][crsum] = (take+notTake) % MOD;
}

int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return solve(0, 0, k, arr, dp);
}

// DP Tabulation, Space Complexity: O(n*k)

const int MOD = 1e9+7;

int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    // dp[n] means reached end of array, dp[n][crsum] means reached end of array with crsum
	for (int crsum=0; crsum < k+1; crsum++){
		dp[n][crsum] = (crsum == k) ? 1 : 0;        // if crsum == 1, 1 subset is found
	}

	for (int i=n-1; i>=0; i--){
		for ( int crsum=k; crsum>=0; crsum--){
			int take=0, notTake=0;

			if (crsum + arr[i] <= k)
				take = dp[i+1][crsum+arr[i]];

			notTake = dp[i+1][crsum];

			dp[i][crsum] = (take+notTake) % MOD;
		}
	}

	return dp[0][0];
}