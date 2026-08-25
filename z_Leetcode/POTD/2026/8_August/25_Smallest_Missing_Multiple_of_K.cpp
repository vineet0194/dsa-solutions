/*
Problem: 3718. Smallest Missing Multiple of K
Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/
Difficulty: Easy
Approach: Hashing + Enumeration
Time Complexity: O(n+m)
Note:
    
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set;
        
        for (auto &num : nums)
            set.insert(num);
        
        int mul=1;
        
        while (true){
            if (set.find(k*mul)==set.end())
            break;
            
            mul++;
        }
        
        return k*mul;
    }
};