/*
Problem: 3483. Unique 3-Digit Even Numbers
Link: https://leetcode.com/problems/unique-3-digit-even-numbers/description/?envType=daily-question&envId=2026-09-11
Difficulty: Easy
Approach: Brute Force
Time Complexity: O(n^3)
Note:
    
*/

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> nums;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k)
                        continue;

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                    if (num >= 100 && num % 2 == 0)
                        nums.insert(num);
                }
            }
        }

        return nums.size();
    }
};