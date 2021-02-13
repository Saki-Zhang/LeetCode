// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = INT_MAX;
        
        for(int price : prices) {
            max_profit = max(max_profit, price - min_price);
            min_price = min(min_price, price);
        }
        
        return max_profit;
    }
};