#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    if (n == 0 || n == 1)
        return 0;

    int i = 0, j = 1;

    int itr = 0;

    int maxProfit = 0;

    while (i < n && j < n && itr < n)
    {

        if (prices[itr] <= prices[i])
        {
            i = itr;
            j = itr;
            int t = itr;

            while (t < n){
                if(prices[t] > prices[i] && prices[t] > prices[j]){
                    j = t;
                }
                t++;
            }

            if(j == n){
                return maxProfit;
            }
            else{
                maxProfit = max(maxProfit, prices[j] - prices[i]);
                // itr = j;
            }
        }

        itr++;
    }

    return maxProfit;
}

int main(){

// vector<int> prices = {7, 1, 5, 3, 6, 4};
// vector<int> prices = {7, 6, 4, 3, 1};
vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

cout << "Max Profit : " << maxProfit(prices);

    return 0;
}