#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &arr)
{

    for (auto x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    return;
}

// 1 2 3
void nextPermutation(vector<int> &nums)
{

    int n = nums.size();

    int itr = n - 2;

    bool flag = false;

    while (itr >= 0)
    {

        if (nums[itr] < nums[itr + 1])
        {
            swap(nums[itr], nums[itr + 1]);
            flag = true;
            break;
        }

        else
        {

            int t = itr;

            while (nums[t] > nums[itr + 1] && t >= 0)
            {
                t--;
            }

            if (t == -1)
            {
                break;
            }

            swap(nums[t], nums[itr + 1]);

            int k = t + 1, l = itr + 1;

            while (k <= l)
            {
                swap(nums[k++], nums[l--]);
            }

            flag = true;
            break;
        }

        itr--;
    }

    if (!flag)
    {

        int k = 0;
        int l = nums.size() - 1;
        while (k <= l)
        {
            swap(nums[k++], nums[l--]);
        }
    }
}

int main()
{

    vector<int> nums = {3, 2, 1};
    // vector<int> nums = {0, 1, 5, 4, 3, 2};

    nextPermutation(nums);

    printArr(nums);

    return 0;
}