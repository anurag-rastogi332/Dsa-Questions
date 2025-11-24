/*
QUESTION: BEST TIME TO BUY AND SELL STOCK
PLATFORM: LEETCODE
LINK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
DATE: 24-11-2025
LEVEL: EASY

NOTES:
- Track minimum price so far
- Calculate profit at each step
- Time: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int p : prices) {
            minPrice = min(minPrice, p);
            maxProfit = max(maxProfit, p - minPrice);
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;

    cout << s.maxProfit(prices);
    return 0;
}
