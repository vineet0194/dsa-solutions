/*
Problem: Hashing Basics
Link: NA
Difficulty: Easy
Approach: Hashing
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
        3, 3, 3, 3, 3,
        12, 99, 34, 68, 5,
        81, 29, 47, 15, 72
    };

    unordered_map<int, int> mp;
    for (int i=0; i<nums.size(); i++){
        if (mp.find(nums[i])==mp.end())
            mp[nums[i]] = 0;
        mp[i]++;
    }
    int maxFreq = 0;
    int maxElement = -1;

    for (auto &p : mp) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            maxElement = p.first;
        }
    }

    cout << "Element: " << maxElement << ", Frequency: " << maxFreq << endl;

    int hash[26];
    string s = "helloworldprogramming";
    for (char c : s) {
        hash[c - 'a']++;
    }

    int maxFreq = 0;
    char maxChar;

    for (int i = 0; i < 26; i++) {
        if (hash[i] > maxFreq) {
            maxFreq = hash[i];
            maxChar = 'a' + i;
        }
    }

    cout << "Character: " << maxChar << ", Frequency: " << maxFreq << endl;

    return 0;
}