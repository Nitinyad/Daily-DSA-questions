class Solution {
public: 
    void solve(int ind , vector<int>& nums , vector<vector<int>> & ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind ; i < nums.size() ; i++){
            swap(nums[ind] , nums[i]);
            solve(ind + 1 , nums , ans);
            swap(nums[ind] , nums[i]);
        }
        return;
    }
    void solve1(vector<int> &nums , vector<int>& freq ,vector<vector<int>> &ans ,vector<int>&ds ){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0 ; i < nums.size() ;i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                solve1(nums,freq,ans,ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //first solution
        vector<int>ds;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int>freq(n,0);
        for(int i = 0 ; i< n ;i++){
            freq[i] = 0;
        }
        solve1(nums,freq, ans,ds);

        return ans;


        //second solution
        // vector<vector<int>> ans;
        // int ind = 0;
        // solve(ind , nums , ans);
        // return ans;
    }
};
