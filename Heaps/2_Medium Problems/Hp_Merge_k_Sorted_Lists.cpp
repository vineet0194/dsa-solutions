/*
Problem: 23. Merge k Sorted Lists
Link: https://leetcode.com/problems/merge-k-sorted-lists/
Difficulty: Hard
Approach: Min Heap
Time Complexity: O(NlogK)
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

// Functor
class CustomComparator{
public:
    bool operator()(auto &a, auto &b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CustomComparator> pq;

        for (int i=0; i<lists.size(); i++){
            if (lists[i] != NULL)
                pq.emplace(lists[i]);
        }
        
        ListNode* root = new ListNode();
        ListNode* it = root;

        while (!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();

            it->next = curr;
            if (curr->next != NULL){
                pq.emplace(curr->next);
            }
            it = curr;
            it->next = NULL;
        }

        return root->next;
    }
};