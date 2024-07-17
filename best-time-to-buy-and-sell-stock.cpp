/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            // Update the minimum price seen so far
            minPrice = min(minPrice, price);
            
            // Calculate the potential profit if we sell at the current price
            int potentialProfit = price - minPrice;
            
            // Update the maximum profit if the potential profit is greater
            maxProfit = max(maxProfit, potentialProfit);
        }
        
        return maxProfit;
    }
};