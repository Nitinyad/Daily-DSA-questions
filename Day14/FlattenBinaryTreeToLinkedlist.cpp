// FIRST SOLUTION USING MORRISE TRAVERSAL
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root ;
        while(curr!=NULL){
            if(curr -> left != NULL){
                TreeNode* prev = curr -> left;
                while(prev->right){
                    prev = prev -> right;
                }
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
        
    }
};

// SECOND SOLUTION USING STACK 
if(root == NULL){
    return;
}
stack<TreeNode*> st;
st.push(root);
while(!st.empty()){
    TreeNode* curr = st.top();
    st.pop();
    if(curr -> right != NULL){
        st.push(curr->right);
    }
    if(curr -> left){
        st.push(curr->left);
    }

    if(!st.empty()){
        curr->right = st.top();
    }
    curr -> left = NULL;
}


