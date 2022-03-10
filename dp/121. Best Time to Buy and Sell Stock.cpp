//
// Created by Jolen on 2022/3/10.
//

int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int profit = 0;
    for(auto price:prices){
        if(price<minPrice)
            minPrice=price;
        else
            profit = max(profit,price-minPrice);
    }
    return profit;
}