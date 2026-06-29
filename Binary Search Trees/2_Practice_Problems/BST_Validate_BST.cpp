/*
Problem: 98. Validate Binary Search Tree
Link: https://leetcode.com/problems/validate-binary-search-tree/description/
Difficulty: Medium
Approach: DFS + BS
Time Complexity: O(nlogn) for my solution
                 O(n) for optimal solution
Note:
    return (leftMax < root->val && isValidBST(root->left));
    return (root->val < rightMin && isValidBST(root->right));

    in these cases, we check the comparison first because leftMax and rightMin are member variables
    which may change value when we call isValidBST() again. if we do comparison after changes,
    comparisons will be done with the new (overwritten) answers and WILL return wrong answer.

    for optimal solution of O(n) we calculate and pass min and max values along with the root in recursive calls
    for on the fly comparisons, init. min and max as NULL
    if (root->val doesnot pass the intervals test => return false)
    if passes both interval tests,
    check if the left and right subtrees are BST
        if we go left => our root becomes the max val while min stays the same
        if we go right => our root becomes the min val while max stays the same

    basically the same approach but pushing min and max with root is more efficient

    ! scroll down for optimal solution !
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

/* --------------------------------------------------------------------------------------------------------------- */

// OPTIMAL SOLUTION

class Solution {
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if (root == NULL)
            return true;
            
        if (min != NULL && root->val <= min->val)
            return false;
        if (max != NULL && root->val > max->val)
            return false;
        
        return helper(root->left, min, root) && helper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root){
        return helper(root, NULL, NULL);
    }
};
