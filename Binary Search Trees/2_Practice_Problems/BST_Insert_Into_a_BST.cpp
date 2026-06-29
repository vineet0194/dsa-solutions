/*
Problem: 701. Insert into a Binary Search Tree
Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
Difficulty: Medium
Approach: BST Insertion
Time Complexity: O(logn)
Note:
    when you get a root == NULL, that means that is exactly the insertion point as the value
    is expected there but we are getting a NULL, hence we create the node there and return it
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        
        if (val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        else if (val > root->val){
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};