/*
Problem: Ceil in BST
Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
Difficulty: Medium
Approach: Binary Search in BST
Time Complexity: O(h)
Note:
    Ceil: smallest number that is equal to or greater than x.

    basically, recurse through the array using binary search method
    initiate ans = -1.
    if at a root, some data is >= k and it is < ans ===> smallest number i.e >= k
    
    ** if you initiate ans from -1 and set the condition if (root->data >= k && root->data < ans) then update
    ! it will never update the ans since you wont find a value less than -1 in this tree (constraints) !
    so to escape this, update only when (root->data >= k && (ans == -1 || root->data < ans))
    if (ans == -1) then update happens for the first time, rest all updates happen for (root->data < ans)
    then push that root->data to ans and look for the next possible smaller value
*/

class Solution {
  public:
    void findCeilInBST(Node* root, int k, int& ans){
        if (root == NULL)
            return;
        
        if (root->data >= k && (ans == -1 || root->data < ans))
            ans = root->data;
        
        if (k == root->data)
            return;
        else if (k < root->data)
            return findCeilInBST(root->left, k, ans);
        else if (k > root->data)
            return findCeilInBST(root->right, k, ans);
    }
    
    int findCeil(Node* root, int x) {
        int ans = -1;
        if (root == NULL)
            return -1;
        findCeilInBST(root, x, ans);

        return ans;
        
    }
};

/* --------------------------------------------------------------------------------------------------------------- */

// iterative approach

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ans = -1;
        
        while (root){
            if (root->data == x)
                return x;
                
            else if (root->data > x){
                ans = root->data;
                root = root->left;
            }
            else
                root = root->right;
        }
        
        return ans;
    }
};
