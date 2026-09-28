#include<iostream>
#include<vector>
using namespace  std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

Node* IP(Node* root){
    while(root->right != NULL){
        root = root->right;
    }

    return root;
}

Node* IS(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}


vector<int> getPredSucc(Node* root, int key){
    Node* curr = root;
    
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if(key < curr->val){
            succ = curr;
            curr = curr->left;
        }else if(key > curr->val){
            pred = curr;
            curr = curr->right;
        }else{
            if(curr->left != NULL){
                pred = IP(curr->left);
            }

            if(curr->right != NULL){
                succ = IS(curr->right);
            }

            break;
        }
    }

    return {pred->val, succ->val};
}

int main(){
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 5;
    vector<int> ans = getPredSucc(root, key);
    cout<<"Predecessor: "<<ans[0]<<endl;
    cout<<"Successor: "<<ans[1]<<endl;
    return 0;
}

// inorder predecessor and successor of Node:
// IP is rightmost node in left subtree and IS is leftmost node in right subtree