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
node* search(node* root,int k){
    if(root == NULL){
        return NULL;
    }

    if(root->data == k){
        return root;
    }

    if(root->data > k){
        return search(root->left,k);
    }
    else{
        return search(root->right,k);
    }
}
node* LCA(node* root,node* p,node* q){
    if(root == NULL){
        return NULL;
    }

    if(root->data > p->data && root->data > q->data){
        return LCA(root->left,p,q);
    }
    else if(root->data < p->data && root->data < q->data){
        return LCA(root->right,p,q);
    }
    else{
        return root;
    }
}
int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    node* root = BuildBST(arr);

    cout << "\nInorder traversal: ";
    inorder(root);

    int pValue, qValue;

    cout << "\n\nEnter first node: ";
    cin >> pValue;

    cout << "Enter second node: ";
    cin >> qValue;

    node* p = search(root, pValue);
    node* q = search(root, qValue);

    if(p == NULL || q == NULL) {
        cout << "\nOne or both nodes do not exist in the tree.";
        return 0;
    }

    node* ans = LCA(root, p, q);

    cout << "\nLCA of " << pValue << " and " << qValue
         << " is: " << ans->data << endl;

    return 0;
}