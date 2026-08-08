/*
Problem: 3302. Find the Lexicographically Smallest Valid Sequence
Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/?envType=daily-question&envId=2026-08-08
Difficulty: Medium
Approach: Greedy subsequence matching with suffix preprocessing
Time Complexity: O(n + m)
Note:
    
*/

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> rightHandSideMatchLength(n, 0);

        int rightMatched = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0) {
            if(j >= 0 && word1[i] == word2[j]) {
                rightMatched++;
                j--;
            }

            rightHandSideMatchLength[i] = rightMatched;
            i--;
        }

        vector<int> seq;
        bool changePower = true; //can change only one character

        i = 0;
        j = 0;
        while(i < n && j < m) {
            if(word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if(changePower == true && i+1 < n && rightHandSideMatchLength[i+1] >= m-j-1) {
                seq.push_back(i);
                j++;
                changePower = false;
            }

            i++;
        }

        return j == m ? seq : vector<int>();
    }
};