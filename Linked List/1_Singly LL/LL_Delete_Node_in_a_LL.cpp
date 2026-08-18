/*
Problem: 237. Delete Node in a Linked List
Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
Difficulty: Medium
Approach: In-place deletion
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next->next != NULL){
            node->val = node->next->val;
            node = node->next;
        }

        node->val = node->next->val;
        node->next = NULL;
    }
};