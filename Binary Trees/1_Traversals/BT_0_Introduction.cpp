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

static int idx=-1;
Node* buildTreePre(vector<int> preArr){
    idx++;
    if (preArr[idx]==-1 || idx >= preArr.size())
        return NULL;
    Node* root = new Node(preArr[idx]);
    root->left = buildTreePre(preArr);
    root->right = buildTreePre(preArr);
    return root;
}

void printPreOrder(Node* root){
    if (root == NULL){
        cout << -1 << " ";
        return;
    }

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(Node* root){
    if (root == NULL){
        cout << -1 << " ";
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPostOrder(Node* root){
    if (root == NULL){
        cout << -1 << " ";
        return;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

void printLevelOrder(Node* root){
    queue<Node*> que;
    que.push(root);
    
    while (!que.empty()){
        if (que.front() == NULL){
            cout << -1 << " ";
            que.pop();
            continue;
        }
        cout << (que.front())->data << " ";
        que.push(que.front()->left);
        que.push(que.front()->right);
        que.pop();
    }
}

// void printLevelOrder2(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty()){
//         Node* curr = q.front();
//         q.pop();
        
//         if (curr == NULL){
//             if (!q.empty())
            
//         }
//     }

// }


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* t1 = buildTreePre(preorder);

    // cout << root->data;
    // cout << root->left->data;
    // cout << root->right->data;

    cout << "Preorder Traversal: "; printPreOrder(t1); cout << endl;
    cout << "Inorder Traversal: "; printInOrder(t1); cout << endl;
    cout << "Postorder Traversal: "; printPostOrder(t1); cout << endl;
    cout << "Levelorder Traversal: ", printLevelOrder(t1); cout << endl;

    return 0;
}