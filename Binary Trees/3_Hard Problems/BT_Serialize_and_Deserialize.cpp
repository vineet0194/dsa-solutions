/*
Problem: 297. Serialize and Deserialize Binary Tree
Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
Difficulty: Hard
Approach: Preorder Traversal + String manipulation + Preorder Creation
Time Complexity: O(n)
Note:
    
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preOrder(TreeNode* root, string& preString){
        if (root == NULL){
            preString += "x, ";
            return;
        }
        preString += to_string(root->val) + ", ";
        preOrder(root->left, preString);
        preOrder(root->right, preString);
    }

    TreeNode* buildTreeUsingPreorder(vector<int>& preArr, int& preIdx){
        preIdx++;
        if (preIdx >= preArr.size() || preArr[preIdx] == -1001)
            return NULL;

        TreeNode* root = new TreeNode(preArr[preIdx]);
        root->left = buildTreeUsingPreorder(preArr, preIdx);
        root->right = buildTreeUsingPreorder(preArr, preIdx);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string preString = "";
        preOrder(root, preString);
        return preString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "-1, ")
            return nullptr;

        vector<int> preArr;
        string curr="";
        int i=0;
        while (i<data.size()){
            if ( data[i] == '-' || isdigit(data[i]) ){
                curr += data[i];
            }
            else if ( data[i] == 'x' ){
                curr += "-1001";            // null catcher
            }
            else if ( data[i] == ',' ){
                preArr.emplace_back(stoi(curr));
                curr = "";
            }
            i++;
        }
        for (auto it : preArr)
            cout << it << " ";
        int preIdx = -1;
        TreeNode* root = buildTreeUsingPreorder(preArr, preIdx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));