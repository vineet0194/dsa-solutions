/*
Problem: 347. Top K Frequent Elements
Link: https://leetcode.com/problems/top-k-frequent-elements/
Difficulty: Medium
Approach: Heaps
Time Complexity: O(n) + O(mlogm) + O(klogm) => m is the number of unique elements in nums
Note:
    
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto& num: nums)
            freq[num]++;

        priority_queue<pair<int, int>> pq;
        for (auto& it: freq)
            pq.push({it.second, it.first});

        vector<int> ans;
        for (int i=0; i<k; i++){
            int curr = pq.top().second;
            pq.pop();
            ans.emplace_back(curr);
        }

        return ans;
    }
};