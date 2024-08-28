

class Solution {
public:
    bool solve(TreeNode* root , int sum , int target){
        if(root == NULL){
            return false;
        }
        sum += root -> val;
        if(root->left == NULL && root -> right == NULL){
            return sum == target;
        }
        bool leftResult = solve(root->left ,sum , target);
        bool rightResult =solve(root ->right, sum ,target);
        return leftResult || rightResult;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root , 0 ,targetSum);
    }
};
