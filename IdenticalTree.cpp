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
int main(){

    vector<int> tree1 = {1,2,-1,-1,3,-1,-1};
    node* root1 = builtBST(tree1);

    vector<int> tree2 = {1,2,-1,-1,3,-1,-1};
    node* root2 = builtBST(tree2);

    cout<<isIdentical(root1,root2)<<endl;

    return 0;
}