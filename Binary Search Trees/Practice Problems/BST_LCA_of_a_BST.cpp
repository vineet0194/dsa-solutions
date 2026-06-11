/*
Problem: 235. Lowest Common Ancestor of a Binary Search Tree
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
Difficulty: Medium
Approach: DFS + BST
Time Complexity: O(h)
Note:
    LCA logic from tree, just added BST's principle to account where you need to go (left or right)
    if both values are lesser than root's current value => go left
    if both values are greater than root's current value => go right
    if at any point you find a node such that p lies to the left and q lies to the right (or vice-versa)
        => LCA
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        TreeNode* leftA=NULL, *rightA=NULL;
        if (root->val < p->val && root->val < q->val){
            rightA = lowestCommonAncestor(root->right, p, q);
            return rightA;      // go right since both values are greater
        }
        else if (p->val < root->val  && q->val < root->val){
            leftA = lowestCommonAncestor(root->left, p, q);
            return leftA;       // go left since both values are smaller
        }
        return root;        // at any point none of the other conditions match
                            // only possible if (p < val < q) || (q < val < p) || (root = p) || (root = q)
                            // this node becomes the LCA
    }
};