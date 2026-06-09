/*
Problem: 98. Validate Binary Search Tree
Link: https://leetcode.com/problems/validate-binary-search-tree/description/
Difficulty: Medium
Approach: DFS + BS
Time Complexity: O(nlogn)
Note:
    return (leftMax < root->val && isValidBST(root->left));
    return (root->val < rightMin && isValidBST(root->right));

    in these cases, we check the comparison first because leftMax and rightMin are member variables
    which may change value when we call isValidBST() again. if we do comparison after changes,
    comparisons will be done with the new (overwritten) answers and WILL return wrong answer.
*/

class Solution {
public:
    int rightMin = INT_MAX;
    void findMin(TreeNode* root) {
        if (root == NULL)
            return;
        if (root->val < rightMin)
            rightMin = root->val;
        findMin(root->left);
        findMin(root->right);
    }

    int leftMax = INT_MIN;
    void findMax(TreeNode* root) {
        if (root == NULL)
            return;
        if (root->val > leftMax)
            leftMax = root->val;
        findMax(root->left);
        findMax(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        
        
        if (root->left == NULL && root->right == NULL)
            return true;
        else if (root->right == NULL){
            leftMax = INT_MIN;
            findMax(root->left);
            return (leftMax < root->val && isValidBST(root->left));
        }
        else if (root->left == NULL){
            rightMin = INT_MAX;
            findMin(root->right);
            return (root->val < rightMin && isValidBST(root->right));
        }
        else if (isValidBST(root->left) && isValidBST(root->right)){
            leftMax = INT_MIN; rightMin = INT_MAX;
            findMax(root->left); findMin(root->right);
            if (leftMax < root->val && root->val < rightMin)
                return true;
        }
        return false;
    }
};