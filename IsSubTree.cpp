#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};
static int idx = -1;
node* builtBST(vector<int> tree){
    idx++;
    if(tree[idx] == -1){
        return NULL;
    }
    node* root = new node(tree[idx]);
    root->left = builtBST(tree);
    root->right = builtBST(tree);

    return root;
}
bool isIdentical(node* p,node* q){
    if(p == NULL || q == NULL){
        return p==q;
    }
    bool isleftsame = isIdentical(p->left,q->left);
    bool isrightsame = isIdentical(p->right,q->right);

    return isleftsame && isrightsame && (p->data == q->data);
}
bool isSubTree(node* root,node* subroot){
    if(root == subroot){
        return root == subroot;
    }
    if(root->data == subroot->data && isIdentical(root,subroot)){
        return true;
    }
    return isSubTree(root->left,subroot) || isSubTree(root->right,subroot);
}
int main() {

    // Main tree
    vector<int> tree = {
        1,
        2,
        4, -1, -1,
        5, -1, -1,
        3,
        6, -1, -1,
        7, -1, -1
    };

    // Subtree
    vector<int> subTree = {
        2,
        4, -1, -1,
        5, -1, -1
    };

    // Build main tree
    node* root = builtBST(tree);

    // Build subtree
    node* subroot = builtBST(subTree);

    // Check subtree
    if (isSubTree(root, subroot)) {
        cout << "Subtree is present" << endl;
    }
    else {
        cout << "Subtree is NOT present" << endl;
    }

    return 0;
}