/*
Problem: 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2026-09-01
Difficulty: Medium
Approach: Single-Pass Traversal + Critical Point Index Tracking
Time Complexity: O(n)
Note:
    
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int last = -1;
        ListNode* curr = head;

        vector<int> arr;

        int i=0;
        while (curr->next != NULL){
            if (last != -1){
                if (
                    ((curr->val > last) && (curr->val > curr->next->val)) ||
                    ((curr->val < last) && (curr->val < curr->next->val))
                    )
                    arr.emplace_back(i);
            }
            i++;
            last = curr->val;
            curr = curr->next;
        }

        vector<int> ans = {INT_MAX, INT_MIN};

        for (int i=0; i+1 < arr.size(); i++){
            ans[0] = min(ans[0], abs(arr[i]-arr[i+1]));
        }

        if (arr.size() > 1)
            ans[1] = max(ans[1], abs(arr[0]-arr[arr.size()-1]));
        
        ans[0] = (ans[0] == INT_MAX) ? -1 : ans[0];
        ans[1] = (ans[1] == INT_MIN) ? -1 : ans[1];

        return ans;
    }
};