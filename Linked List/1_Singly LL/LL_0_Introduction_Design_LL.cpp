/*
Problem: 707. Design Linked List
Link: https://leetcode.com/problems/design-linked-list/description/
Difficulty: Medium
Approach: Singly Linked List Implementation
Time Complexity: 
    - get(index): O(n)
    - addAtHead(val): O(1)
    - addAtTail(val): O(n)
    - addAtIndex(index, val): O(n)
    - deleteAtIndex(index): O(n)
Note:
    
*/

class Node{
public:
    int data;
    Node* next;

    Node (int val){
        this->data = val;
        this->next = NULL;
    }
};

class MyLinkedList {
    Node* root;
public:
    MyLinkedList() {
        root = new Node(-1);
    }
    
    int get(int index) {
        Node* it = root;
        
        int i = -1;
        while (it != NULL && i < index){
            it = it->next;
            i++;
        }

        if (it == NULL)
            return -1;

        return it->data;
    }
    
    void addAtHead(int val) {
        Node* right = root->next;
        Node* curr = new Node(val);
        
        root->next = curr;
        curr->next = right;
    }
    
    void addAtTail(int val) {
        Node* it = root;
        
        while (it->next != NULL)
            it = it->next;
        
        Node* curr = new Node(val);
        it->next = curr;
    }
    
    void addAtIndex(int index, int val) {
        Node* it = root;

        int i = -1;
        while (it != NULL && i < index-1){
            it = it->next;
            i++;
        }
        
        if (it == NULL)
            return;

        Node* right = it->next;
        Node* curr = new Node(val);

        it->next = curr;
        curr->next = right;
    }
    
    void deleteAtIndex(int index) {
        Node* it = root;

        int i = -1;
        while (it != NULL && i < index-1){
            it = it->next;
            i++;
        }

        if (it == NULL || it->next == NULL)
            return;

        Node* temp = it->next;
        it->next = it->next->next;

        delete(temp);
    }
};