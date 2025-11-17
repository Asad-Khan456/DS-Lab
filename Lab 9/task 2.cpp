#include <iostream>
using namespace std;
class Node{
public:
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k){
        key = k;
        left = right = nullptr;
        height = 1;
    }
};
class AVL{
private:
    int height(Node* n){
        if(n){
            return n->height;
        }
        else{
            return 0;
        }
    }
    int getBalance(Node* n){
        if(n){
            return height(n->left) - height(n->right);
        }
        else{
            return 0;
        }
    }
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* t = x->right;


        x->right = y;
        y->left = t;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* t = y->left;


        y->left = x;
        x->right = t;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    Node* insertNode(Node* node, int key){
        if(!node){
            return new Node(key);
        }
        if(key < node->key)
        {
            node->left = insertNode(node->left, key);
        }
        else if(key > node->key)
        {
            node->right = insertNode(node->right, key);
        }
        else
        {
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if(balance > 1 && key < node->left->key){
            return rightRotate(node);
        }
        if(balance < -1 && key > node->right->key){
            return leftRotate(node);
        }
        if(balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }



        return node;
    }
public:
    Node* root = nullptr;
    void insert(int key){
        root = insertNode(root, key);
    }
    void rangeQuery(Node* node, int X, int Y){
        if (node == nullptr){
            return;
        }
        if (node->key > X){
            rangeQuery(node->left, X, Y);
        }
        if (node->key >= X && node->key <= Y){
            cout << node->key << " ";
        }
        if (node->key < Y){
            rangeQuery(node->right, X, Y);
        }
    }
};


int main(){
    AVL tree;
    int prices[] = {100, 40, 300, 150, 75, 20, 507, 250};
    for (int p : prices){
        tree.insert(p);
    }
    int X, Y;
    cout << "Enter X: ";
    cin >> X;
    cout << "Enter Y: ";
    cin >> Y;
    cout << "Prices b/w " << X << " and " << Y << ": ";
    tree.rangeQuery(tree.root, X, Y);
    return 0;
}
