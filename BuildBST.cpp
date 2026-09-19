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
node* insert(node* root,int val){
    if(root == NULL){
        return new node(val);
    }
    if(root->data > val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
node* BuildBST(vector<int> arr){
    node* root = NULL;
    for(int val : arr){
        root = insert(root,val);
    }
    return root;
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool search(node* root,int k){
    if(root == NULL){
        return false;
    }

    if(root->data == k){
        return true;
    }

    if(root->data > k){
        return search(root->left,k);
    }
    else{
        return search(root->right,k);
    }
}
node* getInorderSuccessor(node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}
node* deleteNode(node*& root,int k){
    if(root == NULL){
        return NULL;
    }
    if(root->data > k){
        root->left = deleteNode(root->left,k);
    }
    else if(root->data < k){
        root->right = deleteNode(root->right,k);
    }
    else{
        if(root->left != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right != NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right,IS->data);
        }
    }
    return root;
}
int main(){

    vector<int> arr = {3,2,1,5,6,4};
    node* root = BuildBST(arr);
    inorder(root);
    cout<<endl;

    int k;
    cout<<"Enter k:";
    cin>>k;

    if(search(root,k)){
        cout<<k<<" is present in BST";
        root = deleteNode(root,k);
        cout<<"\nAfter Delete:"<<endl;
        inorder(root);
    }
    else{
        cout<<k<<" is not present in BST";
    }

}