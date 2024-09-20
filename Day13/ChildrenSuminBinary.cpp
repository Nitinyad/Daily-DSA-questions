class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root == NULL){
        return 1;
     }
     //checking if the left and right root reaches the null then return 1;
     if(root->left == NULL && root ->right == NULL){
         return 1;
     }
     int leftroot = 0 , rightroot = 0;
     if(root ->left){
         leftroot = root -> left -> data;
     }
     if(root -> right){
         rightroot = root -> right -> data;
     }
      // if left root and right root sum is not equal to the root then return 0;
     if(root -> data != leftroot + rightroot ){
         return 0;
     }
     // for further calls of left and right of the root;
     return isSumProperty(root -> left) && isSumProperty(root -> right);
     
    }
};
