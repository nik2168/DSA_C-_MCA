#include <iostream>
#include <vector>
#include<map>
using namespace std;

// recursive approach

// int longestSubarray(int i, int n, vector<int> &arr, int k)
// {

//     if (i >= n)
//         return 0;

//     int res = 0;
//     for (int j = 0; j < n - i; j++)
//     {
//         int sum = 0;
//         for (int l = i; l < n - j; l++)
//         {
//             sum += arr[l];
//         }
//         if (sum == k)
//             res = max(((n - j) - i), res);
//     }

//     return max(res, longestSubarray(i + 1, n, arr, k));
// }


// map approach ...
int longestSubarray(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    int ans = 0;

    unordered_map<int, int> preSumM;

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(sum == k){
           ans = i + 1; 
        }
        
        int rem = sum - k;

        if (preSumM.find(rem) != preSumM.end())
        {
            ans = max(ans, i - preSumM[rem]);
        }

        if(preSumM.find(sum) == preSumM.end()){
        preSumM[sum] = i;
        }
    }

    return ans;
}

// optimal two pointer approach but onlu for positive ones ...

// [1 2 3 6] -> only works with positive or zero values
int longestSubarrayTwoPointer(vector<int> & arr, int k){
    int i = 0, j = 0;

    int sum = 0, ans = 0;

    while(i < arr.size() && j < arr.size()){
        
          sum += arr[j++];

          if(sum == k){
            ans = max(ans, j - i);
          }
          if(sum > k){
            while(sum > k) sum -= arr[i++];
            if(sum == k){
                ans = max(ans, j - i);
            }
          }

    }
    return ans;
}

int main()
{

    // vector<int> arr = {10, 5, 2, 7, 1, -10};
    vector<int> arr = {1, 2, 3, 6};

    // int k = 15;
    int k = 5;

    cout<<longestSubarray(arr, k)<<endl;
    cout<<longestSubarrayTwoPointer(arr, k)<<endl;

    // cout << longestSubarray(0, arr.size(), arr, k) << endl;

    return 0;
}