/*
Problem: 3090. Maximum Length Substring With Two Occurrences
Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/?envType=daily-question&envId=2026-08-14
Difficulty: Easy
Approach: Brute Force with Frequency Counting.
Time Complexity: O(n^3)
Note:
    
*/

class Solution {
public:
    void resetArray(int* freq){
        for (int i=0; i<26; i++) {
            freq[i] = 0;
        }
    }

    bool helper(int* freq){
        for (int i=0; i<26; i++){
            if (freq[i] > 2)
                return false;
        }

        return true;
    }


    int maximumLengthSubstring(string s) {
        int n = s.size();

        vector<string> substrings;

        for (int i=0; i<n; i++){
            string temp = "";
            for (int j=i; j<n; j++){
                temp += s[j];
                substrings.emplace_back(temp);
            }
        }

        int freq[26] = {0};
        int maxLength = 1;

        for (int i=0; i<substrings.size(); i++){
            resetArray(freq);

            for (auto& ch: substrings[i])
                freq[ch-'a']++;

            if (helper(freq))
                maxLength = max(maxLength, (int) substrings[i].size());
        }

        return maxLength;
    }
};