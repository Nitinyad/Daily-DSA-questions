#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int val;
    Node* left ;
    Node* right ;
    Node(int data){
        this->val =data;
        left = NULL;
        right = NULL;
    }
};

bool blackbox(Node* root , int node , vector<int> &path){
    if(!root){
        return false;
    }
    path.push_back(root->val);
    if(root->val == node){
        return true;
    }
    if(blackbox(root->left , node , path) || blackbox(root->right , node ,path)){
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> findpath(Node* root , int p , int  q){
    vector<int> path1;
    blackbox(root , p , path1);
    vector<int> path2 ;
    blackbox(root , q , path2);
    vector<int> ans;
    int intersection = -1;
    int i = 0 , j = 0;
    while(i!=path1.size() || j != path2.size()){
        if(i == j && path1[i] == path2[j]){
            i++;j++;
        }
        else{
            intersection = j - 1;
            break;
        }
    }
    for(int i = path1.size() -1 ; i > intersection ; i--){
        ans.push_back(path1[i]);
    }
    for(int i = intersection ; i < path2.size() ; i++){
        ans.push_back(path2[i]);
    }
    
    return ans;
}


int main()
{
    Node* root = new Node(0);
    root ->left = new Node(1);
    root ->right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right ->left = new Node(5);
    root -> right -> right = new Node(6);
    
    root -> left -> left -> left = new Node(7);
    root -> left -> right -> left = new Node(8);
    root -> left -> right -> right = new Node(9);
    
    vector<int> ans = findpath(root , 7 , 4);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
