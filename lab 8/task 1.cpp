#include "iostream"
using namespace std;
class person{
    public:
    string name;
    person* mother;
    person* father;
    person(string name){
        name = name;
        mother = NULL;
        father = NULL;
    }
};
class FTree{
    public:
    person* root;
    FTree(){
        root = NULL;
    
    }
    void setRoot(person *r){
        root = r;

    }
    person *addM(person *child, string name){
        child->mother = new person(name);
        return child->mother;
    }
    person *addF(person *child, string name){
        child->father = new person(name);
        return child->father;
    }
    void displayYoungest(){
        cout << "Root:" << root->name << endl;
        
    }
    void displayLeaves(person* node){
        if(node == NULL){
            return;
        }
        if(node->mother == NULL && node->father== NULL){
                cout << node->name << ",";
        }
                displayLeaves(node->mother);
                displayLeaves(node->father);
    }
    void DisplayLVL(person* node, int LVL){
        if(node == NULL ){
            return;
        }
        cout << node->name << "at Level" << LVL << endl;
        
        DisplayLVL(node->mother,LVL+1);
        DisplayLVL(node->father,LVL+1);
    }
    int height(person* node){
        if(node == NULL ){
            return -1;
        }
        int lh = height(node->mother);
        int rh = height(node->father);
        return (lh > rh ? lh:rh) + 1;

    }

};
int main(){
    FTree tree;
    person* root = new person("Ahmed");
    tree.setRoot(root);
    person* m1 = tree.addM(root, "Zara");
    person* f1 = tree.addF(root, "Ali");
    person* m2 = tree.addM(m1, "Fatima");
    person* f2 = tree.addF(m1, "Hamza");
    person* m3 = tree.addM(f1, "Sana");
    person* f3 = tree.addF(f1, "Imran");
    tree.addM(m2, "Ayesha");
    tree.addF(m2, "Usman");
    tree.addM(f2, "Khadija");
    tree.addF(f2, "Bilal");
    tree.displayYoungest();
    cout << "Leaf Nodes: " << endl;
    tree.displayLeaves(tree.root);
    cout << "Height of Tree = " << tree.height(tree.root) << endl;
    cout << "Levels of All Members:" << endl;
    tree.DisplayLVL(tree.root, 0);
    return 0;
}
