/*
Problem: 103. Binary Tree Zigzag Level Order Traversal
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
Difficulty: Medium
Approach: BFS on tree
Time Complexity: O(n)
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
    void zzLO(TreeNode* root, vector<vector<int>>& ansArr, vector<int>& currArr){
        queue<TreeNode*> q;
        q.push(root);
        int qsize = q.size();
        while (qsize>0){
            for (int i=0; i<qsize; i++){
                TreeNode* curr = q.front();
                q.pop();
                currArr.emplace_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            qsize = q.size();
            ansArr.emplace_back(currArr);
            currArr.clear();
        }
    }

    void reverseVec(vector<int>& arr){
        int i=0, j=arr.size()-1;
        while (i<j){
            int temp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = temp;
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ansArr;
        vector<int> currArr;

        if (root == NULL)
            return ansArr;
        
        zzLO(root, ansArr, currArr);
        for (int i=0; i<ansArr.size(); i++){
            if (i%2!=0)
                reverseVec(ansArr[i]);
        }
        return ansArr;
    }
};