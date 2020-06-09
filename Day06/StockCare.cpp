/*  Best Time to Buy and Sell Stock II
Solution: Say you have an array prices for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
Constraints:
1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int MAX_PRICE_VALUE = pow(10, 4);
int maxProfit(vector<int> &prices)
{
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int maxprofit = 0;
    if( prices.size() == 0 ||
    prices.size() > (3 * MAX_PRICE_VALUE))
        return maxprofit;

    while (i < prices.size() - 1)
    {
        while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
            i++;
        valley = prices[i];

        while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
            i++;
        peak = prices[i];

        maxprofit += peak - valley;
    }
    return maxprofit;
}
int main(void)
{
    vector<int> number;
    number.push_back(7);
    number.push_back(1);
    number.push_back(5);
    number.push_back(3);
    number.push_back(6);
    number.push_back(4);
    cout << "Input Data :";
    for (int num : number)
    {
        cout << num << "\t";
    }
    cout << endl;
    cout << "Result: " << maxProfit(number) << endl;
    ;
    return 0;
}