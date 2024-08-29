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


//BACKTRACKING 
class Solution {
public:
    void solve(TreeNode* root , int& num,int &sum ){
        if(!root){
            return ;
        }
        num = num * 10 + root -> val;
        if(!root -> left && ! root -> right ){
            sum +=  num;
        }
        solve(root -> left , num ,sum);
        solve(root -> right , num , sum);
        num -= root -> val;
        num /= 10;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int num = 0;
        solve(root , num , sum);
        return sum;
    }
};
