
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        int n = inorder.size();
        for(int i = 0 ;i < n ;i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(postorder , 0 , postorder.size() - 1, 
         inorder , 0 , inorder.size() - 1 , mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder , int poststart , int postend , vector<int> & inorder , int instart ,int inend , map<int,int>&mpp){
        if(instart > inend || poststart > postend){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot = mpp[postorder[postend]];
        int numsleft = inroot - instart;
        root -> left = buildTree(postorder , poststart , poststart + numsleft -1, inorder , instart , inroot - 1,mpp);
        root -> right = buildTree(postorder , poststart + numsleft , postend - 1 , inorder , inroot + 1, inend,mpp);
        return root ;
    }
};
