/*
Problem: Basic Array Introduction with:
            Largest and Second Largest Element
            Linear Search
            
Link: NA
Difficulty: Easy
Approach: Linear Search
Time Complexity: -
Note:
    
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {
    42, 7, 91, 18, 63,
    25, 84, 3, 57, 76,
    12, 99, 34, 68, 5,
    81, 29, 47, 15, 72
    };

    int max = nums[0], secMax = -1;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] > max){
            secMax = max;
            max = nums[i];
        }
    }

    cout << "largest: " << max << endl;
    cout << "second largest: " << secMax << endl;

    return 0;
}