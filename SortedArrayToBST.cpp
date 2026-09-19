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
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* BuildBST(vector<int> arr){
    node* root = NULL;
    for(int val : arr){
        root = insert(root,val);
    }
    return root;
}
node* sortedArrayToBST(vector<int>& v,int st,int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end - st) / 2;
    node* root = new node(v[mid]);

    root->left = sortedArrayToBST(v,st,mid-1);
    root->right = sortedArrayToBST(v,mid+1,end);

    return root;
}
int main(){

    int n;
    cout<<"Enter size:";
    cin>>n;
    vector<int> v(n);

    cout<<"Enter value:";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    node* root = sortedArrayToBST(v,0,n-1);
    cout<<"Tree:"<<endl;
    inorder(root);

    return 0;
}