//first approach 
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m , vector<int>(n));
        if(m * n != original.size()){
            return {};
        }
        int ind = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                ans[i][j] = original[ind];
                ind++;
            }
        }

        return ans;
    }
};


//second approach -- important 
// whenever we have to convert the 1d array to 2d array then , ( given the 1d array , row * col -- 2d array )
// to find the particular element from 1d array goes to 2d array 
// row = i / col;
// col = i % col;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m , vector<int>(n));
        if(m * n != original.size()){
            return {};
        }
        for(int i = 0; i < original.size() ; i++){
            ans[i/n][i%n] = original[i];
        }

        return ans;
    }
};
