/*
Problem: 875. Koko Eating Bananas
Link: https://leetcode.com/problems/koko-eating-bananas/description/
Difficulty: Medium
Approach: BS over a range of possible answers
Time Complexity: O(nlogM) m=> max val in piles
Note:
    minimizing the maximum number of bananas he can eat in an hour
*/

class Solution {
public:
    bool isThisRateFeasible(vector<int> arr, int val, int h){
        long long hoursCounted=0;
        for (int i=0; i<arr.size();i++){
            hoursCounted += ceil((double)arr[i]/val);
        }
        if (hoursCounted <= h)
            return true;
        else
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int n = piles.size();
        int l=1, h=piles[0], ans;

        for (auto& it: piles){
            if (it > h)
                h = it;
        }

        while (l<=h){
            int m = l+(h-l)/2;
            if (isThisRateFeasible(piles, m, hr)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};