/*
Problem: Find out how many times the array has been rotated
Link: https://takeuforward.org/arrays/find-out-how-many-times-the-array-has-been-rotated
Difficulty: Easy
Approach: Binary Search
Time Complexity: O(logn)
Note:
    using this approach, we can find minimum element if we return arr[mid]
    the index at which min elem is how many times the array has been rotated
    intuition: 1 shift, shifts the minimum index (earlier at 0) to 1
               2 shift, shifts the min to 2
               x => x
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr){
    int l=0, h=arr.size()-1, mid;
    while (l<=h){
        mid = l+(h-l)/2;
        if (arr[mid] <= arr[h])
            h = mid-1;
        else
            l = mid+1;
    }
    return mid;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {4,5,6,7,0,1,2,3};

    cout << solve(arr);

    return 0;
}