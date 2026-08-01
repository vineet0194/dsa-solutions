/*
Problem: Count Valid Prefixes©leetcode
Link: https://leetcode.com/contest/biweekly-contest-188/problems/count-valid-prefixes/
Difficulty: Easy
Approach: Prefix Counting
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        vector<int> zero_prefix(n, 0);
        vector<int> one_prefix(n, 0);

        if (s[0] == '0')
            zero_prefix[0] = 1;
        else
            one_prefix[0] = 1;
        
        for (int i=1; i<n; i++){
                zero_prefix[i] = zero_prefix[i-1] + (s[i]=='0');
                one_prefix[i] = one_prefix[i-1] + (s[i]=='1');
        }

        int ans = 0;
        for (int i=0; i<n; i++){
            if (abs(zero_prefix[i] - one_prefix[i]) <= 1)
                ans++;
        }

        return ans;
    }
};