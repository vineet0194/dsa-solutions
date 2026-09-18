/*
Problem: 1520. Maximum Number of Non-Overlapping Substrings
Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/?envType=daily-question&envId=2026-09-18
Difficulty: Hard
Approach: Greedy + Interval Expansion + Sorting/Selection
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isValid(26, true);

        vector<string> result;

        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if(start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }

        for(int c = 0; c < 26; c++) { //checking all characters
            if(start[c] == -1) continue;

            
            for(int i = start[c]; i <= end[c]; i++) {
                if(start[s[i]-'a'] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                end[c] = max(end[c], end[s[i]-'a']);
            }
        }

        int lastTakenStart = INT_MAX;

        for(int i = n-1; i >= 0; i--) {
            int c = s[i] - 'a';

            if(!isValid[c]) continue;

            if(i == start[c] && end[c] < lastTakenStart) {
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};
