/*
Problem: 1967. Number of Strings That Appear as Substrings in Word
Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/?envType=daily-question&envId=2026-06-29
Difficulty: Easy
Approach: Substring generation + hashing
Time Complexity: O(n^3)
Note:
    
*/

class Solution {
public:
    void generateAllSS(string& s, unordered_set<string> &st){
        for (int i=0; i < s.size(); i++) {
            string curr = "";
            for (int j=i; j < s.size(); j++) {
                curr += s[j];
                st.insert(curr);
            }
        }
        return;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> set;
        generateAllSS(word, set);

        int count=0;

        for (auto& pattern : patterns){
            if (set.find(pattern)!=set.end())
                count++;
        }

        return count;
    }
};