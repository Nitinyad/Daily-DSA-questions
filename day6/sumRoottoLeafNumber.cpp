class Solution {
public:
    int solve(TreeNode* root , int num){
        if(!root){
            return 0;
        }
        num = num * 10 + root -> val;
        if(!root -> left && ! root -> right ){
            return num;
        }
        return solve(root -> left , num )+solve(root -> right , num); 
    }
    int sumNumbers(TreeNode* root) {
        return solve(root , 0);
    }
};
