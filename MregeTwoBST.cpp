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
void inorder(node* root,vector<int>& arr){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    arr.push_back(root->data);
    inorder(root->right);
}
node* MergeTwoBst(node* root1,node* root2){
    vector<int> arr1,arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);

    vector<int> temp;
    int i=0,j=0;

    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i++]);
        }
        else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i < arr1.size()){
        temp.push_back(arr1[i++]);
    }
    while(j < arr2.size()){
        temp.push_back(arr2[j++]);
    }

    return sortedArrayToBST(temp,0,temp.size()-1);
}
int main() {

    int n1, n2;

    cout << "Enter number of elements in first BST: ";
    cin >> n1;

    vector<int> arr1(n1);

    cout << "Enter elements of first BST: ";
    for(int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "\nEnter number of elements in second BST: ";
    cin >> n2;

    vector<int> arr2(n2);

    cout << "Enter elements of second BST: ";
    for(int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Build two BSTs
    node* root1 = BuildBST(arr1);
    node* root2 = BuildBST(arr2);

    // Display first BST
    cout << "\nInorder of First BST: ";
    inorder(root1);

    // Display second BST
    cout << "\nInorder of Second BST: ";
    inorder(root2);

    // Merge both BSTs
    node* mergedRoot = MergeTwoBst(root1, root2);

    // Display merged BST
    cout << "\nInorder of Merged BST: ";
    inorder(mergedRoot);

    cout << endl;

    return 0;
}