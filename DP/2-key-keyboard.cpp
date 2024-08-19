// LEETCODE QUESTION LINK : https://leetcode.com/problems/2-keys-keyboard/




class Solution {
public:
    int solve(int n , vector<int>&dp ){
        if( n == 1){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int minop = n;
        for(int i = 2 ; i * i <= n ; i++){
            if(n % i == 0){
                minop = min(minop , n / i + solve(i , dp));
                minop = min(minop , i + solve(n / i , dp));
            }
        }
        return dp[n] = minop;
    }
    int minSteps(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n , dp);
    }
};
