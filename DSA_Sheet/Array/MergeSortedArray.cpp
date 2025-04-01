#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    for (int i = m - 1; i >= 0; i--)
    {
        if (i >= n)
        {
            nums1[i] = nums1[i - n];
        }
        else
            nums1[i] = 0;
    }


    int i = 0, j = 0, k = n;

    while (k < m && j < n)
    {
        if (nums1[k] < nums2[j])
            nums1[i++] = nums1[k++];
        else nums1[i++] = nums2[j++];
    }

    while (k < m)
    {
            nums1[i++] = nums1[k++];
    }
    while (j < n)
    {
         nums1[i++] = nums2[j++];
    }


    return;
}

int main(){

vector<int>nums1 = {1,2,3,0,0,0};
vector<int>nums2 = {2,5,6};
int m  = nums1.size();
int n = nums2.size();

merge(nums1, m, nums2, n);

for(auto x : nums1)
cout<<x<<" ";

    return 0;
}