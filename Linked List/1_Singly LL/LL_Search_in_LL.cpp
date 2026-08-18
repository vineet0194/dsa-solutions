/*
Problem: Search in Linked List
Link: https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1
Difficulty: Easy
Approach: Linear Search
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        while (head != NULL){
            if (head->data == key)
                return true;
            
            head = head->next;
        }
        
        return false;
    }
};
