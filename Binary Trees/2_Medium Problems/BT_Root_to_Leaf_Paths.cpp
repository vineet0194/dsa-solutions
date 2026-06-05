/*
Problem: Root to Leaf Paths
Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
Difficulty: Medium
Approach: Preorder DFS + Backtracking and choice
Time Complexity: O(n)
Note:
    
*/

class Solution {
  public:
    void rootToPath(Node* root, vector<vector<int>>& ans, vector<int>& curr){
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL){
            curr.push_back(root->data);
            ans.emplace_back(curr);
            curr.pop_back();
        }
        curr.emplace_back(root->data);
        if (root->left)
            rootToPath(root->left, ans, curr);
        if (root->right)
            rootToPath(root->right, ans, curr);
        curr.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        rootToPath(root, ans, curr);
        return ans;
        
    }
};