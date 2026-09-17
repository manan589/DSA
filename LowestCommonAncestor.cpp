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
node* buildBST(vector<int> tree){
    idx++;
    if(tree[idx] == -1){
        return NULL;
    }
    node* root = new node(tree[idx]);
    root->left = buildBST(tree);
    root->right = buildBST(tree);
    return root;
}
node* LCA(node* root,node* p,node* q){
    if(root == NULL){
        return NULL;
    }
    if(root->data == p->data || root->data == q->data){
        return root;
    }
    node* leftLCA = LCA(root->left,p,q);
    node* rightLCA = LCA(root->right,p,q);

    if(leftLCA && rightLCA){
        return root;
    }
    else if(leftLCA != NULL){
        return leftLCA;
    }
    else{
        return rightLCA;
    }
}
int main(){

    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildBST(tree);
    node* p = root->left->right;
    node* q = root->right->right;

    node* ans = LCA(root,p,q);

    if(ans != NULL){
        cout<<"LCA = "<<ans->data<<endl;
    }
    else{
        cout<<"LCA not found"<<endl;
    }

    return 0;
}