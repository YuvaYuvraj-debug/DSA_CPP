#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int val){
        this->val = val;
        left = right = next = NULL;
    }
};

Node* connect(Node* root){
    if(root == NULL){
        return NULL;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(q.empty()){
                break;
            }

            q.push(NULL);
        }else{
            if(curr->left != NULL){
                q.push(curr->left);
            }

            if(curr->right != NULL){
                q.push(curr->right);
            }

            curr->next = q.front();
        }
    }
	return root;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root = connect(root);

    cout<<root->left->next->left->next->val<<endl;
    return 0;
}