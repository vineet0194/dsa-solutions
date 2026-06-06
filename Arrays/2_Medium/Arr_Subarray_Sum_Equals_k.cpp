/*
Problem: 560. Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k/description/
Difficulty: Medium
Approach: Hashing, prefix sum
Time Complexity: O(n)
Note:
    prefix sum array keeps track of sum uptil the current element in nums
    prefix sum map keeps track of the sums found uptil the current element and how many times such sum was found
    a new target is made => (prefixSum[i] - k) => if this is present in the map for any given previous subarray,
    the count is increased by howm any times it had occured before (so as to account for multiple subarray having the same sum)
    curr prefixsum is always added to the map as we iterate, for first occurence -> insert, else update counts
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> prefixSum = {nums[0]};

        if (nums.size() == 1){
            if (nums[0] == k)
                return 1;
            else
                return 0;
        }
        
        unordered_map<int, int> preSumMap;  // umap<presum, occ.count>
        preSumMap[0]=1;

        for (int i=1; i<nums.size(); i++){
            prefixSum.emplace_back(nums[i] + prefixSum[i-1]);
        }

        for (int i=0; i<prefixSum.size(); i++){
            int tar = prefixSum[i] - k;
            // compliment match found, increase count by how many times
            // the compliment match was found
            if (preSumMap.find(tar) != preSumMap.end())
                count += preSumMap[tar];

            // first occurence of a presum in map
            if (preSumMap.find(prefixSum[i]) == preSumMap.end())
                preSumMap[prefixSum[i]] = 0;
            // other occurences
            preSumMap[prefixSum[i]]++;
        }

        return count;
    }
};