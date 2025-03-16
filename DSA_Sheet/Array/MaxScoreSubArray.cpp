#include <iostream>
#include <vector>
using namespace std;

int pairWithMaxSum(vector<int> &arr)
{

int res = INT_MIN;

for(int i = 0; i < arr.size() - 1; i++){
    res = max(res, arr[i] + arr[i + 1]);
}

    return res;
}

int main()
{

    // vector<int> arr = {4, 3, 1, 5, 6};
    vector<int> arr = {228, 394, 463, 227, 388, 757, 782, 238, 967}; // 1539
    // vector<int> arr = {475, 994, 507, 669, 872, 190, 491}; // 1541

    cout << "Result : " << pairWithMaxSum(arr);

    return 0;
}