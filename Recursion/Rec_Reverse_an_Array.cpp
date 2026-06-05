/*
Problem: Reverse an Array using Recursion
Link: NA
Difficulty: Easy
Approach: Recursion
Time Complexity: O(n)
Note:
    
*/

#include<bits/stdc++.h>
using namespace std;

void revArr(vector<int>& arr, int i, int n){
    if (i > n/2)
        return;
    int temp = arr[i];
    arr[i] = arr[n-1-i];
    arr[n-1-i] = temp;
    revArr(arr, i+1, n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    revArr(arr, 0, arr.size());

    for (auto it : arr)
        cout << it << " ";
    cout << endl;

    return 0;
}