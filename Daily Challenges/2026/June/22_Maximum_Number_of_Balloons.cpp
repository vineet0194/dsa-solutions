/*
Problem: 1189. Maximum Number of Balloons
Link: https://leetcode.com/problems/maximum-number-of-balloons/?envType=daily-question&envId=2026-06-22
Difficulty: Easy
Approach: Hashing
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for (int i=0; i<text.size(); i++){
            freq[text[i]-'a']++;
        }

        int ans=0;
        while (true){
            if ((freq['b'-'a'] >= 1) && (freq['a'-'a'] >= 1) &&
                (freq['l'-'a'] >= 2) && (freq['o'-'a'] >= 2) && (freq['n'-'a'] >= 1)){
                    freq['b'-'a'] -= 1;
                    freq['a'-'a'] -= 1;
                    freq['l'-'a'] -= 2;
                    freq['o'-'a'] -= 2;
                    freq['n'-'a'] -= 1;
                    ans++;
            }else
                break;
            }

        return ans;
    }
};