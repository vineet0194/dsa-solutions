/*
Problem: Print Longest Common Subsequence
Link: https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM
Difficulty: Hard
Approach: DP
Time Complexity: O(n * m * L), L => length of LCS
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*m*L + max(n,m)) [at worst, recursion stack => n+m]

string solve(int i, int j, string& s1, string& s2, vector<vector<string>>& dp){
	if (i == s1.size() || j == s2.size())
		return "";
	
	if (dp[i][j] != "-")
		return dp[i][j];

	if (s1[i] == s2[j])
		return dp[i][j] = s1[i] + solve(i+1, j+1, s1, s2, dp);

	string incI="", incJ="";

	incI = solve(i+1, j, s1, s2, dp);
	incJ = solve(i, j+1, s1, s2, dp);

	if (incI.size() > incJ.size())
		return dp[i][j] = incI;
	else
		return dp[i][j] = incJ;
}

string findLCS(int n, int m, string &s1, string &s2) {
	vector<vector<string>> dp(n, vector<string>(m, "-"));
	return solve(0, 0, s1, s2, dp);
}

// DP Tabulation, Space Complexity: O(n*m*L)

string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<string>> dp(n+1, vector<string>(m+1, "-"));

	for (int i=0; i<n+1; i++)
		dp[i][m] = "";

	for (int i=0; i<m+1; i++)
		dp[n][i] = "";

	
	for (int i=n-1; i>=0; i--){
		for (int j=m-1; j>=0; j--){
			if (s1[i] == s2[j]){
				dp[i][j] = s1[i] + dp[i+1][j+1];
				continue;
			}
			string incI="", incJ="";

			incI = dp[i+1][j];
			incJ = dp[i][j+1];

			if (incI.size() > incJ.size())
				dp[i][j] = incI;
			else
				dp[i][j] = incJ;
		}
	}

	return dp[0][0];
}