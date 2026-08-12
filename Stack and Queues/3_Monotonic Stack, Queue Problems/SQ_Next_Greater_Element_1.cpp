/*
Problem: 496. Next Greater Element I
Link: https://leetcode.com/problems/next-greater-element-i/
Difficulty: Easy
Approach: Stacks / Hash Map + Linear Search
Time Complexity: O(n+m)
Note:
    
*/

// Approach 1: using stacks, O(n+m)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;

        int n = nums2.size();

        for (int i=n-1; i>=0; i--){
            while (!st.empty() && st.top() < nums2[i])
                st.pop();
            
            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.emplace(nums2[i]);
        }

        vector<int> ans;
        for (int i=0; i<nums1.size(); i++){
            ans.emplace_back(nge[nums1[i]]);
        }

        return ans;
    }
};

// Approach 2: without using stacks, O(n + mn)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> index;
        
        int n = nums2.size();

        for (int i=0; i<n; i++){
            index[nums2[i]] = i;
        }

        vector<int> ans;

        for (int i=0; i<nums1.size(); i++){
            int idx = index[nums1[i]];
            int nextGreaterIdx = -1;
            for (int j=idx+1; j<n; j++){
                if (nums2[j] > nums2[idx]){
                    nextGreaterIdx = nums2[j];
                    break;
                }
            }
            ans.emplace_back(nextGreaterIdx);
        }

        return ans;
    }
};