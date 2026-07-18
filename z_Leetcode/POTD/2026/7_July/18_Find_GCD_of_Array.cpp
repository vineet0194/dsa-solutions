/*
Problem: 1979. Find Greatest Common Divisor of Array
Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/
Difficulty: Easy
Approach: Min/Max Find + Euclidean Algo for GCD
Time Complexity: O(n + logM) => O(n)        M => smallest number
Note:
        gcd(a,b) => O( log(min(a,b)) )    
*/

class Solution {
public:
    int getGCD(int a, int b){
        if (b == 0)
            return a;
        return getGCD(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];

        for (int i=0; i<nums.size(); i++){
            if (nums[i] > maxi)
                maxi = nums[i];
            else if (nums[i] < mini)
                mini = nums[i];
        }

        return getGCD(maxi, mini);
    }
};