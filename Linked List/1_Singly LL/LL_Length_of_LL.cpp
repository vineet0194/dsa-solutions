/*
Problem: Length of Linked List
Link: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1
Difficulty: Easy
Approach: Linear Iteration + Count
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    int getCount(Node* head) {
        int count = 0;
        
        while (head != NULL){
            count++;
            head = head->next;
        }
        
        return count;
    }
};