#include "iostream"
using namespace std;
class Song{
public:
    int playCount;
    string title;
    Song *left;
    Song *right;
    Song(int p, string t){
        playCount = p;
        title = t;
        left = right = NULL;
    }
};
class MusicBST{
public:
    Song* root;
    MusicBST(){
        root = NULL;
    }
    Song* insert(Song* node, int p, string t){
        if(node == NULL){
            return new Song(p,t);
        }
        if(p < node->playCount){
            node->left = insert(node->left,p,t);
        }
        else if(p > node->playCount){
            node->right = insert(node->right,p,t);
        }
        return node;

    }
    Song* search(Song* node, int p){
        if(node == NULL || node->playCount == p)
        {
            return node;
        } 
        if(p < node->playCount){
            return search(node->left,p);
        }
        else{
            return search(node->right,p);
        }

    }
    void inorder(Song* node){
        if(node == NULL) return;
        inorder(node->left);
        cout << node->title << " (" << node->playCount << ")" << endl;
        inorder(node->right);
    }
    void postorder(Song* node){
        if(node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->title << " (" << node->playCount << ")" << endl;

    }
    Song* findMin(Song* node){
        while(node->left != NULL)
            node = node->left;
        return node;
    }
    Song* deleteNode(Song* node, int p){
        if(node == NULL) return node;

        if(p < node->playCount){
            node->left = deleteNode(node->left,p);
        }
        else if(p > node->playCount){
            node->right = deleteNode(node->right,p);
        }
        else{
            if(node->left == NULL)
            {
                return node->right;
            }
            else if(node->right == NULL)
            {
                return node->left;

            }
            Song* minRight = findMin(node->right);
            node->playCount = minRight->playCount;
            node->title = minRight->title;
            node->right = deleteNode(node->right,minRight->playCount);
        }

        return node;

    }
};
int main(){
    MusicBST tree;
    tree.root = tree.insert(tree.root, 50, "Song A");
    tree.root = tree.insert(tree.root, 70, "Song B");
    tree.root = tree.insert(tree.root, 30, "Song C");
    tree.root = tree.insert(tree.root, 10, "Song D");
    tree.root = tree.insert(tree.root, 60, "Song E");
    tree.root = tree.insert(tree.root, 90, "Song F");
    cout << "\nInorder (Least to Most Played):" << endl;
    tree.inorder(tree.root);
    cout << "\nPostorder (Reverse Popularity Removal Order):" << endl;
    tree.postorder(tree.root);
    int key = 60;
    Song* s = tree.search(tree.root, key);
    if(s != NULL) cout << "\nSong found: " << s->title << endl;
    else cout << "\nSong not found" << endl;
    cout << "\nDeleting Song with 70 plays..." << endl;
    tree.root = tree.deleteNode(tree.root,70);
    cout << "\nUpdated Inorder After Deletion: " << endl;
    tree.inorder(tree.root);
    return 0;
}
