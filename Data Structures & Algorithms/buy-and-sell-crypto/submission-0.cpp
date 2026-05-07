class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = INT_MAX ; //buyprice
        int max_pro = 0 ; //sell price

        for(int p : prices){
            min_price = min(min_price, p);
            max_pro = max(max_pro , p-min_price);
        }
        return max_pro;
        
    }
};
