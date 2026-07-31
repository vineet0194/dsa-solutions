/*
Problem: 3016. Minimum Number of Pushes to Type Word II
Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
Difficulty: Medium
Approach: Counting + Sorting + Greedy
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int minimumPushes(string word) {
        int count[26] = {0};
        
        string str = "";
        for (auto& ch : word){
            if (count[ch-'a'] == 0)
                str += ch;
            count[ch-'a'] += 1;
        }

        sort(str.begin(), str.end(), [&count](const auto& a, const auto& b){
            return count[a-'a'] > count[b-'a'];
        });

        int n = str.size();

        int ans = 0;
        int mul = 1;

        for (int i=0; i<n; i++){
            ans += count[str[i]-'a']*mul;
            if ((i+1)%8 == 0)
                mul++;
        }

        return ans;
    }
};