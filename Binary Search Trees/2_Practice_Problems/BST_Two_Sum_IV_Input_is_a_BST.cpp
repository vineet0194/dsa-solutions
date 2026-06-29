/*
Problem: 653. Two Sum IV - Input is a BST
Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
Difficulty: Easy
Approach: Inorder DFS + Hashing
Time Complexity: O(n) but O(n^2) worst case if map findings take long due to hash collisions
Note:
    
*/

class Solution {
public:
    bool targetFinder(TreeNode* root, int k, unordered_map<int, bool>& visited){
        if (root == NULL)
            return false;

        int target = k-(root->val);
        if (visited.find(target) != visited.end()){
            return true;
        }else{
            visited[root->val] = true;
        }
        bool left = targetFinder(root->left, k, visited);
        bool right = targetFinder(root->right, k, visited);

        return (left || right);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, bool> visited;
        return targetFinder(root, k, visited);
    }
};