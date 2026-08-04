/*
Problem: Is Binary Tree Heap
Link: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
Difficulty: Medium
Approach: BT and Heap Properties
Time Complexity: O(n)
Note:
    2 things for a BT to be a Heap:
        1. must be a complete BT
        2. must follow heap property
*/

/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    bool isComplete(Node* root){
        if (root == NULL)
            return true;
        
        queue<Node*> q;
        q.push(root);
        bool seenNull = false;
        int qsize;
        
        while (!q.empty()){
            qsize = q.size();
            
            for (int k=0; k<qsize; k++){
                Node* curr = q.front();
                q.pop();
                
                if (curr == NULL)
                    seenNull = true;
                else{
                    if (seenNull)
                        return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        
        return true;
    }
    
    bool isMaxHeap(Node* root){
        if (root == NULL)
            return true;
        
        if (root->left == NULL && root->right == NULL)
            return true;
        
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        
        if (root->left && root->data < root->left->data)
            return false;
        
        if (root->right && root->data < root->right->data)
            return false;
        
        return left && right;
    }
    
    bool isHeap(Node* root) {
        bool complete = isComplete(root);
        bool maxHeap = isMaxHeap(root);
        
        if (complete && maxHeap)
            return true;
        
        return false;
    }
};