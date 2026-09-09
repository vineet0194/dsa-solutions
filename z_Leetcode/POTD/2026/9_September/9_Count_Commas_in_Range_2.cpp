/*
Problem: 3871. Count Commas in Range II
Link: https://leetcode.com/problems/count-commas-in-range-ii/?envType=daily-question&envId=2026-09-09
Difficulty: Medium
Approach: Logic
Time Complexity: O(logn)
Note:
    
*/

#define ll long long
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;

        ll lower  = 1000;
        ll commas = 1;

        while(lower <= n) {
            ll upper = lower*1000 - 1;
            if(upper > n) upper = n;

            ll countNumbers = upper - lower + 1;
            result += (countNumbers * commas);

            lower *= 1000;
            commas++;
        }

        return result;
    }
};