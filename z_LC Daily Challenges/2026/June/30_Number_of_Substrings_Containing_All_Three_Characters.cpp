/*
Problem: 1358. Number of Substrings Containing All Three Characters
Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2026-06-30
Difficulty: Medium
Approach: Sliding Window
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {0};

        int i=0, j=0, n=s.size(), ans=0;

        while (i < n-2){        // i goes from 0 to n-3 [min window size = 3]
            while (j<n && !(freq[0] && freq[1] && freq[2])){
                freq[s[j]-'a']++;
                j++;
            }
            if (freq[0] && freq[1] && freq[2])       // valid window found
                ans += n-j+1;
            else
                break;      // if there isnt a valid window for i, there wont be any for i+1 to n-3

            // now keep j there but remove i from window and inc
            freq[s[i]-'a']--;
            i++;
        }

        return ans;
    }
};