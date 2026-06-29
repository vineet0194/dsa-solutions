/*
Problem: Kth largest element in BST
Link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
Difficulty: Easy
Approach: Inorder DFS
Time Complexity: O(n)
Note:
    BST follows Inorder Traversal => sorted order
    reverse inorder will give us reverse sorted order (decreasing order)
    Hence we can do reverse Inorder Traversal and keep a count of the nodes visited,
    when count == k => we have found the kth largest element
*/

class Solution {
  public:
    void helper(Node* root, int k, int& i, int& kthLargest){
        if (root == NULL)
            return;
        
        helper(root->right, k, i, kthLargest);
        i++;
        if (i == k){
            kthLargest = root->data;
            return;
        }
        helper(root->left, k, i, kthLargest);
        
    }
  
    int kthLargest(Node *root, int k) {
        int i=0, kthLargest=-1;
        helper(root, k, i, kthLargest);
        return kthLargest;
    }
};