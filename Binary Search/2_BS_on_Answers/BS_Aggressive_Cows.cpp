/*
Problem: Aggressive Cows
Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1
Difficulty: Medium
Approach: BS over a range of possible answers
Time Complexity: O(nlog(maxpos-minpos))
Note:
    maximizing the minimum distance between any 2 cows
*/

class Solution {
  public:
    bool cowCanBePlaced(vector<int>& stalls, int val, int cowsLeft){
        int last=0;
        cowsLeft--;
        for (int i=0; i<stalls.size(); i++){
            if (stalls[i]-stalls[last] >= val){
                cowsLeft--;
                last = i;
            }
            if (cowsLeft == 0)
                return true;
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        if (k > stalls.size())
            return -1;
        
        int n = stalls.size(), l=1, h = stalls[n-1]-stalls[0], m, ans;
        while (l<=h){
            m=l+(h-l)/2;
            if (cowCanBePlaced(stalls, m, k)){
                ans=m;
                l=m+1;
            }
            else
                h=m-1;
        }
        return h;
    }
};