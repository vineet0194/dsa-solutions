/*
Problem: BST Introduction
    Insertion, Search, Deletion
Link: NA
Difficulty: Easy
Approach: -
Time Complexity: Insertion O(logn) average, O(n) worst if skewed
                 Search O(logn)    average, O(n) worst
                 Deletion O(logn)  average, O(n) worst
Note:
    O(logn) is actually O(h), if the tree is also balanced then max h = logn, therefore O(logn)

    a good rule of thumb to digest this new "root->left = insert(root->left, val)" kind of syntax is:
    !We don't yet know what the left child of root should be after insertion, so we ask recursion to figure it out and return it!
    same with the right subtree
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

void inorder(Node* root){
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key){
    // O(h) => for balanced BST, O(logN)

    if (root == NULL)
        return false;
    
    if (key < root->data)
        return search(root->left, key);
    else if (key > root->data)
        return search(root->right, key);
    else
        return true;

}

unordered_map<int, int> inorderSuccessorMap;
int inorderSuccessor(int val){
    return inorderSuccessorMap[val];
}
// or
// Node* inorderSuccessor(Node* root){
//     Node* inSuc = root->left;
//     while (inSuc!=NULL && inSuc->left != NULL)
//         inSuc = inSuc->right;
    
//     return inSuc;
// }

Node* deleteNode(Node* root, int key){
    if (root == NULL)
        return NULL;    // key not found
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else{   // key == root
        if (root->left == NULL && root->right == NULL){           // 0 children
            return NULL;
        }
        else if (root->left == NULL){                             // 1 child, only right exists
            Node* temp = root->right;
            delete root;                                          // delete curr and return its right child
            return temp;
        }
        else if (root->right == NULL){                            // 1 child, only left exists
            Node* temp = root->left;
            delete root;
            return temp;                                          // delete curr and return its right child
        }                                  
        else{                                                     // 2 child
            int IS = inorderSuccessor(root->data);              
            root->data = IS;                                    // find IS and swap val of curr with IS
            root->right = deleteNode(root->right, IS);          // delete IS, IS will always exist in the right subtree of curr
        }                                                       // therefore, "delete IS from curr's right subtree"
    }                                                           // do not use root here, you will delete current node
    return root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // BUILDING
    vector<int> arr = {3, 2, 1, 5, 6, 4};   // random arr from which BST is to be constructed
    Node* root = buildBST(arr);

    // PRINT
    // inorder(root);
    // cout << endl;
    
    // SEARCH
    cout << search(root, 5) << endl;        // 1
    cout << search(root, 8) << endl;        // 0

    // DELETING
    for (int i=0; i<arr.size(); i++){
        if (i == arr.size()-1)
            inorderSuccessorMap[arr[i]] = -1;
        inorderSuccessorMap[arr[i]] = arr[i+1];
    }
    root = deleteNode(root, 5);         // 1,2,3,4,5,6 => 1,2,3,4,6
    inorder(root);
    cout << endl;

    return 0;
}