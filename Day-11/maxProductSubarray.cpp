
// THIS IS MOST OPTIMAL ONE 
// -- > >>>> find the prefix and suffix then find the max btw them.
// -- if there is even -ve numbers , 
// -- if there is odd -ve numbers ,
// -- if all are posiive \,
// -- if there are zero's --> turn the purfix and suffix to 1
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0 ;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            maxi = max(maxi , max(suffix , prefix));
        }
        return maxi;
    }
};
