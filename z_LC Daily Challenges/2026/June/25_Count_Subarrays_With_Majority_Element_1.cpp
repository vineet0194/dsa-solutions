/*
Problem: 3737. Count Subarrays With Majority Element I
Link: https://leetcode.com/problems/count-subarrays-with-majority-element-i/?envType=daily-question&envId=2026-06-25
Difficulty: Medium
Approach: Subarray Iteration
Time Complexity: O(n^2)
Note:
    
*/

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> majCount(n, 0);

        if (nums[0] == target)
            majCount[0] = 1;

        for (int i=1; i<nums.size(); i++){
            if (nums[i] == target)
                majCount[i] = majCount[i-1]+1;
            else
                majCount[i] = majCount[i-1];
        }

        int ans=0;
        for (int l=0; l<n; l++){        // n iterations
            for (int r=l; r<n; r++){        // (n-l) iterations
                int targetCount;
                int length = r-l+1;
                if (l==0)
                    targetCount = 2*(majCount[r]);
                else
                    targetCount = 2*(majCount[r]-majCount[l-1]);
                
                if (targetCount > length)
                    ans++;
            }
        }
        
        return ans;
    }
};