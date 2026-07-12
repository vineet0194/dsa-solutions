/*
Problem: 3020. Find the Maximum Number of Elements in Subset
Link: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/?envType=daily-question&envId=2026-06-27
Difficulty: Medium
Approach: Greedy + Hashing
Time Complexity: O(n * log(logM))   n=> distinct roots , M=> max value
Note:
    SUBSET, not SUBARRAY

    so choose a starting point, if freq = 2 => consider a pyramid with both freqs making the 2 opp sides, length+2
                                next elem to find = x^2
                                if freq = 1 => this is the peek element, length+1
                                if freq = 0 =? no peak, make peek with what you have, length-1
        at the end, return max length
*/

#define ll long long

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll, ll> mp;
        unordered_set<ll> visited;

        // mapping
        for (int i=0; i<nums.size(); i++){
            if (mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 0;
            mp[nums[i]]++;
        }


        ll maxLength = 1;
        visited.insert(1);
        // 1
        if (mp.find(1) != mp.end()){
            if (mp[1]%2 == 0)
                maxLength = max(maxLength, mp[1]-1);
            else
                maxLength = max(maxLength, mp[1]);
        }


        // non-1
        for (int i=0; i<nums.size(); i++){
            if (visited.find(nums[i])!=visited.end())
                continue;

            ll x = nums[i];            // root
            visited.insert(x);    // set root as visited

            ll currLength = 0;
            while (true){
                if (mp[x] >= 2)
                    currLength += 2;
                else if (mp[x] == 1){
                    currLength += 1;
                    break;
                }
                else if (mp[x] == 0){
                    currLength -= 1;
                    break;
                }
                x *= x;
            }
            if (maxLength < currLength)
                maxLength = currLength;
        }

        return maxLength;
    }
};