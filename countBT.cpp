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
int count(node* root){
    if(root == NULL){
        return 0;
    }
    int leftct = count(root->left);
    int rightct = count(root->right);
    return leftct + rightct + 1;
}
int main(){

    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = builtBST(tree);
    cout<<"COUNT: "<<count(root)<<endl;

    return 0;
}