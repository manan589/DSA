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
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht,rightht)+1;
}
int main(){

    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildBST(tree);
    cout<<"Height: "<<height(root)<<endl;

    return 0;
}