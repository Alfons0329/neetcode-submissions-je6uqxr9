/*
Intuition: the maximum profit will be searched in a continuous non-deterministic length of the 
interval, so we can use the sliding window technique to self this problem


Approach:
    define L := buy, R := sell
    1. // Expand
        R := sell
        L := buy

    2. // Shrink
        if (price[R] - price[L] < 0) {
            L++ // shrink left to see if higher 
        }

    3. // Process
        // we only care about positivie income, otherwise just give up
        if (price[R] - price[L] > 0) {
            res = max(price[R] - price[L], res);
        }

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int L = 0;
        int res = 0, curRes = 0;

        for (int R = 0; R < n; R++) {
            // expand to get the current one
            curRes = prices[R] - prices[L];

            // shrink left side if negative and get lower prices to buy if possible 
            while(prices[R] - prices[L] < 0) {
                L++;
            }

            // find valid answer
            res = max(max(prices[R] - prices[L], 0), res);
        } 


        return res;
    }
};
