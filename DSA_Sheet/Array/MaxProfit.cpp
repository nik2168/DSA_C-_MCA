#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int res = 0;

    int j = 0, k = 0;

    for(int i = 0; i < n; i++){

       if(prices[i] < prices[j]){
           j = i; 
       }

       if(prices[i] > prices[j]){
           k = i;
       }

       if(j < k){
       res = max(res, prices[k] - prices[j]);
       }
    }

    return res;
}

int main(){

// vector<int> prices = {7, 1, 5, 3, 6, 4};
// vector<int> prices = {7, 6, 4, 3, 1};
vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

cout << "Max Profit : " << maxProfit(prices);

    return 0;
}