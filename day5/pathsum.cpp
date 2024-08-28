
// using two pointer

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


//using sliding window
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int i=0;
        int j=0;
        
        int n1=haystack.size();
        int n2=needle.size();
        if(n1<n2)
        return -1;

        string s="";
        int ans=-1;
        while(j<n1)
        {
            s+=haystack[j];
            if(j-i+1==n2)
            {
                if(s==needle)
                {
                    ans=i;
                    break;
                }
                else
                {
                    i++;
                    s.erase(s.begin()+0);
                }
            }
            j++;
        }
        return ans;
    }
};
