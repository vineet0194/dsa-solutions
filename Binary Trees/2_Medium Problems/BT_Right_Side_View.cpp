/*
Problem: 199. Binary Tree Right Side View
Link: https://leetcode.com/problems/binary-tree-right-side-view/
Difficulty: Medium
Approach: Level order BFS
Time Complexity: O(n)
Note:
    catch the first elem, push in ans, use rest only to push children nodes
    trick/intuition to not use deque or other complex items => simply get the right children first
*/

class Solution {
public:
    void rsv(TreeNode* root, vector<int>& ans){
        queue<TreeNode*> q;
        q.push(root);
        int qsize = q.size();
        while (qsize>0){
            for (int i=0; i<qsize; i++){
                TreeNode* curr = q.front();
                q.pop();
                if (i == 0)
                    ans.push_back(curr->val);
                if (curr->right)
                    q.push(curr->right);
                if (curr->left)
                    q.push(curr->left);
            }
            qsize = q.size();
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        rsv(root, ans);
        
        return ans; 
    }
};