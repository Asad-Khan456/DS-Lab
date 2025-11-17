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
    string rotation = "None";
    int height(Node* n){
        if (n) { return n->height; }
        return 0;
    }
    int getBalance(Node* n){
        if (n) { return height(n->left) - height(n->right); }
        return 0;
    }
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* t = x->right;
        x->right = y;
        y->left = t;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        rotation = "Right Rotation (LL Case)";
        return x;
    }
    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* t = y->left;
        y->left = x;
        x->right = t;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        rotation = "Left Rotation (RR Case)";
        return y;
    }
    Node* insertNode(Node* node, int key){
        if(!node){
          return new Node(key);
                   }
        if(key < node->key){
            node->left = insertNode(node->left, key);
        }
        else if(key > node->key){
            node->right = insertNode(node->right, key);
        }
        else{
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        rotation = "None";
        if(balance > 1 && key < node->left->key){
            return rightRotate(node);
        }
        if(balance < -1 && key > node->right->key){
            return leftRotate(node);
        }
        if(balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            rotation = "Left-Right Rotation (LR Case)";
            return rightRotate(node);
        }
        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            rotation = "Right-Left Rotation (RL Case)";
            return leftRotate(node);
        }
        return node;
    }
    Node* minValueNode(Node* node){
        Node* current = node;
        while (current->left){
            current = current->left;
        }
        return current;
    }
    Node* deleteNode(Node* root, int key){
        if(!root){
          return root;
                   }

        if(key < root->key){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left || !root->right){
                Node* temp = root->left ? root->left : root->right;
                if(!temp){
                    temp = root;
                    root = nullptr;
                }
                else{
                    *root = *temp;
                }
                delete temp;
            }
            else{
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (!root){
          return root;
        }
        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);
        rotation = "None";

        if(balance > 1 && getBalance(root->left) >= 0){
            return rightRotate(root);
        }
        if(balance > 1 && getBalance(root->left) < 0){
            root->left = leftRotate(root->left);
            rotation = "Left-Right Rotation (LR Case)";
            return rightRotate(root);
        }
        if(balance < -1 && getBalance(root->right) <= 0){
            return leftRotate(root);
        }
        if(balance < -1 && getBalance(root->right) > 0){
            root->right = rightRotate(root->right);
            rotation = "Right-Left Rotation (RL Case)";
            return leftRotate(root);
        }
        return root;
    }
public:
    Node* root = nullptr;


    void insert(int key){
        cout << "\nNew patient severity: " << key << endl;
        root = insertNode(root, key);
        cout << "Rotation: " << rotation << endl;
        cout << "Tree Height: " << height(root) << endl;
        cout << "Highest Severity Patient: " << getMax() << endl;
    }
    void remove(int key){
        cout << "\nDischarging patient with severity: " << key << endl;
        root = deleteNode(root, key);
        cout << "Rotation: " << rotation << endl;
        cout << "Tree Height: " << height(root) << endl;
        cout << "Highest Severity Patient: " << getMax() << endl;
    }

    int getMax(){
        if (!root)
        {
          return -1;
        }
        Node* current = root;
        while(current->right){
            current = current->right;
        }
        return current->key;
    }
};
int main(){
    AVL tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(80);
    tree.insert(90);
    tree.remove(30);
    tree.remove(70);
    return 0;
}
