//
// Created by Jolen on 2021/6/22.
//

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

////  迭代
//int maxProfit(vector<int> &prices) {
//    if (prices.size() == 0)
//        return 0;
//    int buy = prices[0], profit = 0;
//    for (int i = 1; i < prices.size(); i++) {
//        if (prices[i] <= prices[i - 1]) {
//            profit += prices[i-1]-buy;
//            buy = prices[i];
//        }
//    }
//    profit+=prices[prices.size()-1]-buy;
//    return profit;
//}

int profitOneTime(vector<int> &prices, int start) {
    if (prices.size()-1 == start)
        return 0;
    for (int i = start + 1; i < prices.size(); i++) {
        if (prices[i]<=prices[i-1])
            return prices[i-1]-prices[start]+profitOneTime(prices,i);
    }
}

////    递归
int maxProfit(vector<int> &prices) {
    if (prices.size() == 0)
        return 0;
    return profitOneTime(prices, 0);
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
}