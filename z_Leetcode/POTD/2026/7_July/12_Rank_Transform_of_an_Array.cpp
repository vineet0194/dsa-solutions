/*
Problem: 1331. Rank Transform of an Array
Link: https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2026-07-12
Difficulty: Easy
Approach: Sorting + Hashing
Time Complexity: O(NlogN)
Note:
    
*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> newArr = arr;
        sort(newArr.begin(), newArr.end());

        unordered_map<int, int> rankMap;
        int rank=1;
        for (int i=0; i<n; i++){
            if (rankMap.find(newArr[i]) == rankMap.end()){
                rankMap[newArr[i]] = rank;
                rank++;
            }
        }

        for (int i=0; i<n; i++)
            newArr[i] = rankMap[arr[i]];

        return newArr;
    }
};