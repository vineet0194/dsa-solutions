/*
Problem: 
Link: 
Difficulty: 
Approach: 
Time Complexity: O(n) , O(h)
Note:
    the tricky part in this question is that the key given may/may not even be present in the tree
    and basically need to find 2 values => one that is just smaller than key => floor(key)
    and one that is just greater than key => ceil(key)


    approach1: get the entire inorder sequence
                iterate through it and update pre if pre->data < key
                first instance of pre->data > key is the ceil value (suc) => return
                O(n) for inorder, O(n) for linear search => O(n)

    approach2: traverse the array iteratively using binary search
        if you find the key in the tree =>
                inorder pred and succ is easy, if their children are NOT NULL, simply iterate through
                their left and right children to find the pred and succ (IF CHILDREN ARE NULL THEN KEEP PREV VALUES)
                IF KEY IS PRESENT, YOU FOUND THE FINAL ANSWER AT THIS STEP, NEED NOT TO TRAVERSE FURTHER => BREAK!

        if key is not present in the tree =>
                if curr val < key
                    you must go right, while doing so, curr value should be stored in pre (as it is a possible floor val)
                if curr val > key
                    you must go left, while doing so, curr value should be stored in succ (as it is a possible ceil val)

        when all nodes traversed => return

*/

class Solution {
  public:
    void helper(Node* root, int key, vector<Node*>& inorderNodeArr){
        if (root == NULL)
            return;
        helper(root->left, key, inorderNodeArr);
        inorderNodeArr.push_back(root);
        helper(root->right, key, inorderNodeArr);
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> inorderNodeArr;
        helper(root, key, inorderNodeArr);
        
        Node* pred = NULL;
        Node* succ = NULL;
        for (int i=0; i<inorderNodeArr.size(); i++){
            if ((inorderNodeArr[i]->data) < key)
                pred = inorderNodeArr[i];
            else if ((inorderNodeArr[i]->data) > key){
                succ = inorderNodeArr[i];
                break;
            }
        }
        return {pred, succ};
    }
};

/* --------------------------------------------------------------------------------------------------------------- */

// OPTIMAL SOLUTION     O(h)

void preSucFinder(Node* root, int key, Node*& pre, Node*& suc){
    while (root){
        if (root->data == key){
            if (root->left !=NULL){
                pre = root->left;
                while (pre!=NULL && pre->right !=NULL)
                    pre = pre->right;
            }
            if (root->right !=NULL){
                suc = root->right;
                while (suc!=NULL && suc->left !=NULL)
                    suc = suc->left;
            }
            break;
        }
        else if (root->data < key){
            pre = root;
            root = root->right;
        }
        else{
            suc = root;
            root = root->left;
        }
    }
}

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        preSucFinder(root, key, pre, suc);
        return {pre, suc};
    }
};