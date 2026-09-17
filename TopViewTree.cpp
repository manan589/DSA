#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
void topView(node* root){
    queue<pair<node*,int>> q;
    map<int,int> m;
    q.push({root,0});

    while(q.size() > 0){
        node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data;
        }

        if(curr->left != NULL){
            q.push({curr->left,currHD-1});
        }
        if(curr->right != NULL){
            q.push({curr->right,currHD+1});
        }
    }
    for(auto it : m){
        cout<<it.second<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildBST(tree);
    topView(root);

    return 0;
}