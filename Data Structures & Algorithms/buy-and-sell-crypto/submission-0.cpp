class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map <int, int> higherprice;

        int h = prices[prices.size() - 1];
        for (int i=prices.size()-2; i>=0; i--){
            higherprice[i] = h;
            h = max(h, prices[i]);
        }

        int profit = 0;
        for (int i= 0; i<prices.size()-1; i++){
            int p = higherprice[i] - prices[i];
            profit = max(profit, p);
        }
        return profit;
    }
};
