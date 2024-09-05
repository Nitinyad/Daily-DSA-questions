class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(int i = 0 ; i < rolls.size() ;i++){
            sum += rolls[i];
        }
        int totaln = n + rolls.size();
        int mul = mean * totaln;
        int num = mul - sum;
        if(num < n || num > 6*n) return {}; 
        vector<int> ans(n, num/n);
        int rem = num % n;
        for(int i =0 ; i< rem ;i++){
            ans[i]++;
        }
        return ans;
    }
};
