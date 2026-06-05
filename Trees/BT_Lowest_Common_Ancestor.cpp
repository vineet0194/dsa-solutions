/*
Problem: 236. Lowest Common Ancestor of a Binary Tree
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
Difficulty: Medium
Approach: Preorder DFS
Time Complexity: O(n)
Note:
    if both side of a node return NULL => neither p nor q found
    if either returns NULL => return the valid one
    if both return a valid value => LCA

    if 1 node is under the other (suppose q is in p's subtree)
    then at p's parent node will have (if found in left subtree) leftA = p and rightA = NULL => p becomes the LCA
    therefore, the parent node will be the answer (LCA)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode* leftA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightA = lowestCommonAncestor(root->right, p, q);
        if (leftA == NULL && rightA == NULL)
            return NULL;
        else if (leftA == NULL)
            return rightA;
        else if (rightA == NULL)
            return leftA;
        else
            return root;
    }
};