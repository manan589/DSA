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
void kthLevel(node* root,int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    kthLevel(root->left,k-1);
    kthLevel(root->right,k-1);
}
int main(){

    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildBST(tree);
    kthLevel(root,3);

    return 0;
}