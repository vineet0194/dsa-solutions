/*
Problem: Floor in BST
Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
Difficulty: Easy
Approach: Binary Search in BST
Time Complexity: O(h)
Note:
    Floor : the greatest number in the binary search tree that is less than or equal to k.

    basically, recurse through the array using binary search method
    initiate ans = -1.
    if at a root, some data is <= k and it is > ans ===> greatest number i.e <= k
    so push that root->data to ans and look for the next possible greater value
*/

class Solution {
  public:
    void findFloorInBST(Node* root, int k, int& ans){
        if (root == NULL)
            return;
        
        if (root->data <= k && root->data > ans){
            ans = root->data;
        }
        
        if (k == root->data)
            return;
        else if (k < root->data)
            return findFloorInBST(root->left, k, ans);
        else if (k > root->data)
            return findFloorInBST(root->right, k, ans);
    }
    
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        if (root == NULL)
            return -1;
        findFloorInBST(root, k, ans);
        
        return ans;
    }
};

/* --------------------------------------------------------------------------------------------------------------- */

// iterative approach

class Solution {
  public:
  // ik the func name is incorrect, blame it on GFG haha
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        
        while (root){
            if (root->data == k)
                return k;
            
            else if (root->data < k){
                ans = root->data;
                root = root->right;
            }
            else
                root = root->left;
        }
        return ans;
    }
};