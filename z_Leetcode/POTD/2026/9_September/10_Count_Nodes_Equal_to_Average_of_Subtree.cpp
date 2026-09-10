/*
Problem: 2265. Count Nodes Equal to Average of Subtree
Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2026-09-10
Difficulty: Medium
Approach: Trees
Time Complexity: O(n^2)
Note:
    
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> getSumAndCount(TreeNode* root){
        if (root == NULL)
            return {0, 0};
        
        int count = 1;
        int sum = root->val;

        if (root->left){
            pair<int, int> tempA = getSumAndCount(root->left);
            sum += tempA.first;
            count += tempA.second;
        }
        
        if (root->right){
            pair<int, int> tempB = getSumAndCount(root->right);
            sum += tempB.first;
            count += tempB.second;
        }
        
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int ans = 0;
        pair<int, int> snc = getSumAndCount(root);
        if (snc.first/snc.second == root->val)
            ans++;

        if (root->left)
            ans += averageOfSubtree(root->left);

        if (root->right)
            ans += averageOfSubtree(root->right);

        return ans;
    }
};