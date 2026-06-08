/*
Problem: Find Min/Max in BST
Link: NA
Difficulty: Easy
Approach: Logic
Time Complexity: O(h)
Note:
    in a BST, obv the left most node will be the smallest, right most will be the largest
    since we have the given condition, Left < Root < Right
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int val){
    if (root == NULL){
        Node* curr = new Node(val);
        return curr;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node* buildBST(vector<int>& arr){
    Node* root = NULL;

    for (int i=0; i<arr.size(); i++){
        root = insert(root, arr[i]);
    }
    
    return root;
}

int findMin(Node* root){
    while (root!=NULL && root->left!=NULL)
        root = root->left;
    return root->data;
}

int findMax(Node* root){
    while (root!=NULL && root->right!=NULL)
        root = root->right;
    return root->data;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildBST(arr);

    cout << findMin(root) << endl;
    cout << findMax(root) << endl;

    return 0;
}