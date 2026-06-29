/*
Problem: 450. Delete Node in a BST
Link: https://leetcode.com/problems/delete-node-in-a-bst/description/
Difficulty: Medium
Approach: Search the node, check if it has 0 or 1 or 2 children, delete accordingly
Time Complexity: 
Note:
    if no match found => return NULL;

    if 0 children => delete and return NULL
    if 1 children => delete and return the valid child
    if 2 children => replace curr data with Inorder Successor (will def come from the right of the tree)
                     then delete the Inorder Successor's value from the root's right subtree,
                     this will def have 0 or 1 children and hence will be handled easily
*/

class Solution {
public:
    TreeNode* findInorderSuccessor(TreeNode* root){
        TreeNode* inSuc = root->right;
        while (inSuc!=NULL && inSuc->left!=NULL)
            inSuc = inSuc->left;
        return inSuc;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if (root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if (root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* inSuc = findInorderSuccessor(root);
                root->val = inSuc->val;
                root->right = deleteNode(root->right, inSuc->val);
            }
        }
        return root;
    }
};