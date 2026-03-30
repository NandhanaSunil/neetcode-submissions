class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> higherdays(prices.size(), 0);
        int p = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--){
            p = max(prices[i+1], p);
            higherdays[i] = p;
        }
        int maxp = 0;
        for(int i=0; i<prices.size()-1; i++){
            maxp = max(higherdays[i]-prices[i], maxp);
        }
        return maxp;
    }
};
