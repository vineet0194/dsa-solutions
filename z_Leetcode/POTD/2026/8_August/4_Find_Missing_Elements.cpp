/*
Problem: 3731. Find Missing Elements
Link: https://leetcode.com/problems/find-missing-elements/?envType=daily-question&envId=2026-08-04
Difficulty: Easy
Approach: Hash Set + Linear Search
Time Complexity: O(n+R)
Note:
    
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        int mini = nums[0];
        int maxi = nums[0];

        for (auto& num: nums){
            st.insert(num);
            if (num > maxi)
                maxi = num;
            if (num < mini)
                mini = num;
        }

        vector<int> ans;

        for (int i=mini; i<=maxi; i++){
            if (st.find(i)==st.end())
                ans.push_back(i);
        }

        return ans;
    }
};