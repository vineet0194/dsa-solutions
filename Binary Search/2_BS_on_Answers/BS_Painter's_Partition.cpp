/*
Problem: The Painter's Partition Problem-II
Link: https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
Difficulty: Hard
Approach: Binary Search on Answer Space
Time Complexity: O(nlogS) (s - sum of all the board lengths)
Note:
    boards cant be divided => answer space will be from (max length) to (sum of all lengths)
    if (isFeasible(time)) => store as answer and look for a smaller possible time
    else => look for a larger valid answer
*/

class Solution {
  public:
    bool isThisTimeFeasible(vector<int>& arr, int k, int timeAllwd){
        int paintersReqd=1;
        int currTime=0;
        for (int i=0; i<arr.size(); i++){
            if (currTime+arr[i] <= timeAllwd)
                currTime += arr[i];
            else{
                paintersReqd++;
                currTime=arr[i];
            }
            if (i==arr.size()-1 && paintersReqd <= k)
                return true;
        }
        return false;
    }
  
    int minTime(vector<int>& arr, int k) {
        int l=arr[0], h=0;
        for (auto& num: arr){
            if (num > l)
                l = num;
            h += num;
        }
        
        int ans=-1;
        while (l<=h){
            int mid = l+(h-l)/2;
            if (isThisTimeFeasible(arr, k, mid)){
                ans = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        
        return ans;
    }
};