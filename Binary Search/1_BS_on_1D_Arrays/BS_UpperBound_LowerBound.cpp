/*
Problem: Upper Bound and Lower Bound in Binary Search
Link:   https://takeuforward.org/arrays/implement-upper-bound
        https://takeuforward.org/arrays/implement-lower-bound-bs-2
Difficulty: Easy
Approach: Binary Search
Time Complexity: O(logn)
Note:
    Bounds of a number (eg: target):
        Lower Bound => Smallest element >= Target
        Upper Bound => Smallest element > Target
    usually, we return the index for that bound and that 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1,2,3,3,3,4,5,6};
    int h = arr.size()-1, l=0, target = 3;

    int ans=-1;
    while (l<=h){
        int mid = l+(h-l)/2;
        if (arr[mid] >= target){
            ans = mid;
            h = mid-1;
        }
        else
            l = mid+1;
    }
    cout << "Lower Bound: " << ans << endl;

    l=0, h=arr.size()-1, ans=-1;
    while (l<=h){
        int mid = l+(h-l)/2;
        if (arr[mid] > target){
            ans = mid;
            h = mid-1;
        }
        else
            l = mid+1;
    }
    cout << "Upper Bound: " << ans << endl;

    return 0;
}