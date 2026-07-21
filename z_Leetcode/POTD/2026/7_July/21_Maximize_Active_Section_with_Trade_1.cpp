/*
Problem: 3499. Maximize Active Section with Trade I
Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21
Difficulty: Medium
Approach: Array Simulation
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> prefix;
        int original1 = 0;

        int count0 = 0;
        int count1 = 0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '0'){
                if (count1 != 0){
                    prefix.push_back(count1);
                    count1 = 0;
                }
                count0++;
            }
            else{
                if (count0 != 0){
                    prefix.push_back(count0);
                    count0 = 0;
                }
                original1++;
                count1--;
            }
        }
        if (count0 != 0)
            prefix.push_back(count0);
        if (count1 != 0)
            prefix.push_back(count1);

        int last = -1;
        int maxi = 0;
        for (int i=0; i<prefix.size(); i++){
            if (prefix[i] > 0){
                if (last == -1){
                    last = i;
                    continue;
                }
                int count = prefix[last] + prefix[i];
                last = i;
                maxi = max(maxi, count);
            }
        }
        return original1 + maxi;
    }
};