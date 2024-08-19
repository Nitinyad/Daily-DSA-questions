//LEETCODE QUESTION LINK : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        int mini = prices[0];
        for(int i = 1 ; i < n ;i ++){
            int cost = prices[i] - mini;
            profit = max(profit , cost);
            mini = min(mini , prices[i]);
        }
        return profit;
    }
};
