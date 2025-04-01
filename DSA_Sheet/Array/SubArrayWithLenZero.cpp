#include <iostream>
#include <unordered_map>
using namespace std;

int maxLen(vector<int> &arr)
{
    // code here
    unordered_map<int, int> m;

    int sum = 0;

    int res = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            res = max(res, i + 1);
        }
        if (arr[i] == 0)
        {
            res = max(res, 1);
        }
        if(m.find(sum) != m.end()){
           res = max(res, i - m[sum]);
        }else{
            m[sum] = i;
        }
    }

    return res;
}

int main()
{

    vector<int> arr = {-21, 67, 22, 22, -29, 27, -42};
    // vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << maxLen(arr) << endl;

    return 0;
}