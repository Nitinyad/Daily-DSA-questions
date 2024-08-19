
//LEETCODE QUESTION LINK : https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0) );
        for(int i = 0 ; i< n ;i++){
            for(int j = 0; j < m;j++){
                if(i == j){
                    continue;
                }
                if(vis[i][j] == 0){
                    swap(matrix[i][j] , matrix[j][i]);
                    vis[i][j] = 1;
                    vis[j][i] = 1;
                }
            }
        }
        for(int i = 0; i < n;i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
        
    }
};
