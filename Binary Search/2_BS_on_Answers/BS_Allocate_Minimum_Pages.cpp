/*
Problem: Allocate Minimum Pages
Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
Difficulty: Medium
Approach: BS over a range of possible answers
Time Complexity: O(nlogS) S=> sum of all pages
Note:
    minimizing the maximum number of pages assigned to a student
*/

class Solution {
  public:
    bool canAllocateBooks(vector<int>& arr, int val, int k){
        int currSum=arr[0], studCount=1;
        // studCount will ultimately give how many students
        // are required to complete the allocation for all books
        // with the given max value per student
        // if it is <= k, that means books can be allocated for that max val
        // if an allocation is possible for some students s, it is also possible
        // for k such that s <= k <= N, N is the array size
        for (int i=1; i<arr.size(); i++){
            if (arr[i] > val)
                return false;
            if (currSum + arr[i] <= val){
                currSum += arr[i];
            }
            else{
                currSum = arr[i];
                studCount++;
            }
            if (studCount <= k && i==arr.size()-1)
                return true;
        }
        return false;
    }
  
    int findPages(vector<int> &arr, int k) {
        
        int n=arr.size();
        if (k>n)
            return -1;
        
        int l=arr[0], h=0, ans=-1;

        for (auto it: arr){
            h += it;
            if (it < l)
                l = it;
        }
        
        while (l<=h){
            int mid=l+(h-l)/2;
            if (canAllocateBooks(arr, mid, k)){
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
    }
};