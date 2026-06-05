/*
Problem: 102. Binary Tree Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
Difficulty: Medium
Approach: Iterative BFS using Queue
Time Complexity: O(n)
Note:
    if (curr == NULL) finds true then if the queue isnt empty, it simply means all the children
    of the preceeding nodes (all at the current level) have already been added to the queue
    hence this NULL should be added again back to the queue so as sort of mark a newline
    when the queue is empty and curr == NULL, this means all nodes have been processed, so break.
*/

class Solution {
public:
    void levelOrderPrint(vector<vector<int>>& ans, vector<int>& temp, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while (!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL){
                if (!q.empty()){
                    q.push(curr);   //setup the next newline in queue
                    ans.emplace_back(temp); //put current level in ans
                    temp.clear();
                    continue;
                }
                else{
                    ans.emplace_back(temp); //put final level in ans and exit
                    break;
                }
            }
            // curr is not NULL so,
            temp.emplace_back(curr->val);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }

        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        if (root == NULL)
            return {};
        levelOrderPrint(ans, temp, root);
        return ans;
    }
};