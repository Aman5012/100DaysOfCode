121. Best Time to Buy and Sell Stock

//QUESTION LNK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

TOPIC: arry


CODE:

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]); // Update lowest buy price so far
            int profit = prices[i] - minPrice;   // Profit if sold today
            maxProfit = max(maxProfit, profit);  // Update max profit
        }
        return maxProfit;
    }
};
