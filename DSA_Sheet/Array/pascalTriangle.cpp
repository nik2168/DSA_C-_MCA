#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{

    vector<vector<int>> res;

    res.push_back({1});

    if (numRows == 1)
    {
        return res;
    }

    res.push_back({1, 1});

    if (numRows == 2)
    {
        return res;
    }

    for (int i = 2; i < numRows; i++)
    {
        vector<int> t;

        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                t.push_back(1);
            }
            else
            {
                t.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
        }
        res.push_back(t);
    }

    return res;
}

int main()
{

    vector<vector<int>> res = generate(5);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}