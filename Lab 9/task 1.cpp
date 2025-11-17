#include <iostream>
#include <string>
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
    string lastRotation = "None";
    int height(Node* n){
        return n ? n->height : 0;
    }
    int getBalance(Node* n){
        return n ? height(n->left) - height(n->right) : 0;
    }
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        lastRotation = "Right Rotation (LL Case)";
        printBalanceFactors(y, x);
        return x;
    }
    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        lastRotation = "Left Rotation (RR Case)";
        printBalanceFactors(x, y);
        return y;
    }
    void printBalanceFactors(Node* a, Node* b){
        cout << "B.F after rotation:\n";
        cout << "node " << a->key << " → BF = " << getBalance(a) << endl;
        cout << "Node " << b->key << " → BF = " << getBalance(b) << endl;
    }
    Node* insertNode(Node* node, int key){
        if (!node) return new Node(key);
        if(key < node->key)
            node->left = insertNode(node->left, key);
        else if(key > node->key)
            node->right = insertNode(node->right, key);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        lastRotation = "Nne";
        if(balance > 1 && key < node->left->key)
            return rightRotate(node);
        if(balance < -1 && key > node->right->key)
            return leftRotate(node);
        if(balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            lastRotation = "Left-Right Rotation (LR Case)";
            return rightRotate(node);
        }
        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            lastRotation = "Right-Left Rotation (RL Case)";
            return leftRotate(node);
        }
        return node;
    }
    Node* minValueNode(Node* node){
        Node* current = node;
        while (current->left)
            current = current->left;
        return current;
    }
    Node* deleteNode(Node* root, int key){
        if (!root) return root;
        if(key < root->key)      root->left = deleteNode(root->left, key);
        else if(key > root->key)    root->right = deleteNode(root->right, key);
        else
        {
            if(!root->left || !root->right){
                Node* temp = root->left ? root->left : root->right;
                if(!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else{
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (!root) return root;
        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);
        lastRotation = "None";
        if(balance > 1 && getBalance(root->left) >= 0)      return rightRotate(root);
        if(balance > 1 && getBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            lastRotation = "Left-Right Rotation (LR Case)";
            return rightRotate(root);
        }
        if(balance < -1 && getBalance(root->right) <= 0)    return leftRotate(root);
        if(balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            lastRotation = "Right-Left Rotation (RL Case)";
            return leftRotate(root);
        }
        return root;
    }
public:
    Node* root = nullptr;
    void insert(int key){
        cout << "\n>>> Inserting " << key << endl;
        root = insertNode(root, key);
        cout << "Rotation: " << lastRotation << endl;
        cout << "Tree Height: " << height(root) << endl;
    }
    void remove(int key){
        cout << "\n>>> Deleting " << key << endl;
        root = deleteNode(root, key);
        cout << "Rotation: " << lastRotation << endl;
        cout << "Tree Height: " << height(root) << endl;
    }
};


int main(){
    AVL tree;
    int rolls[] = {30, 20, 40, 10, 25, 50, 5};
    for (int r : rolls)
        tree.insert(r);
    tree.remove(10);
    tree.remove(40);
    tree.remove(20);
    return 0;
}
