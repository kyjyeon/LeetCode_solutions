class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int size = prices.size();
        int profit = 0;
        int bought = 0;           //current bought stock price
        bool transaction = false; //flag to check if the stock is bought or not
        for (i = 0; i < size; i++) {
            if (size == 2) {
                if (i == 0) {
                    if (prices[i] < prices[i + 1])
                        profit = prices[i + 1] - prices[i];
                }
            }
            if (size > 2) {
                if (i == size - 1) {
                    if (transaction == true)//when reached end of index and stock is still bought (Descending case)
                        profit = profit + prices[i] - bought;
                    break;
                }
                if (i == 0) {
                    if (prices[i] < prices[i + 1]) {
                        bought = prices[i];
                        transaction = true;
                    }
                }
                //stock buying case
                else if (prices[i] <= prices[i - 1] && prices[i] < prices[i + 1] && transaction == false) {
                    bought = prices[i];
                    transaction = true;
                }
                //stock selling case
                else if (prices[i] >= prices[i - 1] && prices[i] > prices[i + 1] && transaction == true) {
                    profit = profit + prices[i] - bought;
                    transaction = false;
                }
            }
        }
        return profit;
    }
};