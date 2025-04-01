#include <iostream>
#include <vector>
using namespace std;

vector<int> findTwoElement(vector<int> &arr)
{
    // code here
    vector<int> t(arr.size() + 1, 0);

    vector<int> res(2, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        t[arr[i]]++;
        if (t[arr[i]] > 1)
            res[0] = arr[i];
    }

    for (int i = 1; i <= t.size(); i++)
    {
        if (t[i] == 0)
        {
            res[1] = i;
            break;
        }
    }

    return res;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 6};

    vector<int> res = findTwoElement(arr);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}