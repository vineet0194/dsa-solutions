/*
Problem: 94. Binary Tree Inorder Traversal (Morris Inorder)
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
Difficulty: Easy
Approach: Iterative Inorder DFS
Time Complexity: O(n)
Note:
    basically for Inorder you need to go Left Root Right, but iteratively there isnt a way to get back to root
    once you start exploring the left subtree. therefore, we make a temporary connection of a node (IP) to the root
    IP -> Inorder Predecessor is the node just left to the curr node in a tree's inorder sequence.
    ! IP will always be the rightmost node in the left subtree of the curr node !

    if connection does not exists (IP->right = NULL) then make that connection and then traverse the left subtree
    if connection does exists (IP->right != NULL) => left subtree is already traversed, break conenction and move to right
*/

class Solution {
public:
    TreeNode* findIP(TreeNode* curr){
        TreeNode* IP = curr->left;
        while (IP->right != NULL && IP->right != curr)      // we use IP->right != curr so as to not skip through curr
            IP = IP->right;                                 // during the second time we try to find IP
        return IP;
    }
    void morrisInorder(TreeNode* curr, vector<int>& ans){
        while (!curr == NULL){
            if (curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* IP = findIP(curr);
                if (IP->right == NULL){
                    IP->right = curr;
                    curr = curr->left;
                }
                else{
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        morrisInorder(root, ans);
        return ans;
    }
};