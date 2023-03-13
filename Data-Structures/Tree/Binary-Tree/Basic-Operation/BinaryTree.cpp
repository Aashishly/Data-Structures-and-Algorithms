#include <iostream>
#include <queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};

Node* buildTree(Node* root){

    cout << "Enter the Data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            cout << temp -> data << " ";

            if(temp -> left){
            q.push(temp -> left);
            }

            if(temp -> right){
            q.push(temp -> right);
            }

        }
 
    }
    

}

void inOrderTranversal(Node* root){

    if(root == NULL){
        return;
    }

    inOrderTranversal(root -> left);
    cout << root -> data << " ";
    inOrderTranversal(root -> right);
}

void preOrderTranversal(Node* root){

    if(root == NULL){
        return;
    }

    cout << root -> data << " ";
    preOrderTranversal(root -> left);
    preOrderTranversal(root -> right);
}

void postOrderTranversal(Node* root){

    if(root == NULL){
        return;
    }

    postOrderTranversal(root -> left);
    postOrderTranversal(root -> right);
    cout << root -> data << " ";
}

void buildFromLevelOrder(Node* &root){
    queue <Node*> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }

    }
}

int main(){

    Node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    // root = buildTree(root);


    // levelOrderTraversal(root);

    // cout << "InOrder traversal is: " << endl;
    // inOrderTranversal(root);
    // cout << endl;

    // cout << "PreOrder traversal is: " << endl;
    // preOrderTranversal(root);
    // cout << endl;

    // cout << "PostOrder traversal is: " << endl;
    // postOrderTranversal(root);
    // cout << endl;

    return 0;
}


