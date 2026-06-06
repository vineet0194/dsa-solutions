/*
Problem: Floor and Ceil in Sorted Array
Link: https://takeuforward.org/arrays/floor-and-ceil-in-sorted-array
Difficulty: Easy
Approach: Binary Search
Time Complexity: O(logn)
Note:
    in an array,
    Floor of a number ==> largest number just smaller than or equal to target
    Ceil of a number ==> smallest number just greater than or equal to target
*/

#include<bits/stdc++.h>
using namespace std;

int floorBS(vector<int>& nums, int target){
    int l=0, h=nums.size()-1, ans = -1;
    while (l<=h){
        int mid = l+(h-l)/2;
        if (nums[mid] <= target){
            ans = nums[mid];
            l = mid+1;
        }
        else
            h = mid-1;
    }
    return ans;
}

int ceilBS(vector<int>& nums, int target){
    int l=0, h=nums.size()-1, ans = -1;
    while (l<=h){
        int mid = l+(h-l)/2;
        if (nums[mid] >= target){
            ans = nums[mid];
            h = mid-1;
        }
        else
            l = mid+1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {3,4,4,7,8,10}, nums2 = {3, 4, 4, 7, 8, 10};

    cout << "floor of 5 : " << floorBS(nums1, 5) << endl << "ceil of 5 : " << ceilBS(nums1, 5) <<endl;
    cout << endl;
    cout << "floor of 8 : " << floorBS(nums2, 8) << endl << "ceil of 8 : " << ceilBS(nums2, 8) <<endl;
    
    return 0;
}