
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int , int > mpp;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder , 0 , preorder.size() - 1 , inorder , 0 , inorder.size() - 1 , mpp);
        return root ;
    }

    TreeNode* buildTree(vector<int> &preorder , int preStart , int preEnd , vector<int>& inorder ,int inStart , int inEnd , map<int,int> &mpp ){
        if(inStart > inEnd || preStart > preEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root -> val];
        int numsleft = inRoot - inStart ;

        root -> left = buildTree(preorder , preStart + 1 , preStart + numsleft , inorder , inStart , inRoot - 1 , mpp);
        root -> right = buildTree(preorder , preStart + numsleft + 1 , preEnd , inorder , inRoot + 1 , inEnd , mpp);
        return root ;
    }
};
