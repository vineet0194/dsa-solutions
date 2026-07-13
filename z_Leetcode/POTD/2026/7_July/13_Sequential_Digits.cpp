/*
Problem: 1291. Sequential Digits
Link: https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2026-07-13
Difficulty: Medium
Approach: Brute Force (Precomputed Solution Space Search)
Time Complexity: O(1)
Note:
    
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        const vector<int> solutionSpace = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};

        int n = solutionSpace.size();

        // if low and high are the same values
        if (low == high){
            for (int i=0; i<n; i++){
                if (solutionSpace[i] == low)    // that value is sequential
                    return {low};
            }
            return {};              // not sequential
        }

        int startIndex = -1, endIndex = -1;

        // get the starting index
        for (int i=0; i<n; i++){
            if (solutionSpace[i] >= low){
                startIndex = i;
                break;
            }
        }

        // if no value found that is just ge low
        if (startIndex == -1)
            return {};

        // get the ending index
        for (int i=0; i<n; i++){
            if (solutionSpace[i] > high){
                break;
            }
            endIndex = i;
        }
        
        // slice the solution space into ans
        vector<int> ans;
        for (int i=startIndex; i<=endIndex; i++)
            ans.push_back(solutionSpace[i]);
        
        
        return ans;
    }
};