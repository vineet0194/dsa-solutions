/*
Problem: Missing in Array
Link: https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
Difficulty: Easy
Approach: Math
Time Complexity: O(n)
Note:
    only 1 elem is missing, n are to be expected.
    only natural numbers are given hence sum of first n natural numbers is n*(n+1)/2,
    subtract the sum of present numbers and you will get the missing one
*/

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size()+1;
        long long sum = 0, temp = n*(n+1)/2;
        for (auto it : arr){
            sum += it;
        }
        long long result = temp-sum;
        int res = (int) result;
        
        return res;
    }
};