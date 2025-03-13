#include <iostream>
#include <vector>
using namespace std;

/* Union of Two Sorted Arrays
Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.
NOTE: Elements in the union should be in ascending order.

Examples
Example 1:
Input:

n = 5,m = 5.
arr1[] = {1,2,3,4,5}  
arr2[] = {2,3,4,4,5}
Output:

 {1,2,3,4,5} */


vector<int> unionFinder(vector<int> &nums1, vector<int> &nums2)
{
  
    vector<int> res;

    int i = 0, j = 0;

    if (nums1[i] < nums2[j])
        res.push_back(nums1[i++]);
    else
        res.push_back(nums2[j++]);

    while(i < nums1.size() && j < nums2.size()){
        while(res.back() >= nums1[i] && i < nums1.size()) i++;
        while(res.back() >= nums2[j] && j < nums2.size()) j++;
        if (j >= nums2.size() || i >=nums1.size())
            break;

        if(nums1[i] < nums2[j])  res.push_back(nums1[i++]);
        else res.push_back(nums2[j++]);  
    }

    while(i < nums1.size() && i < nums1.size()){
        while(res.back() >= nums1[i]) i++;
        if (i >= nums1.size())
            break;

        res.push_back(nums1[i++]);
    }

    while(j < nums2.size()){
        while (res.back() >= nums2[j] && j < nums2.size())
            j++;
            if(j >= nums2.size()) break;
        res.push_back(nums2[j++]);
    }

    return res;

}

int main()
{

    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {2,3,4,4,6};

    vector<int>res = unionFinder(nums1, nums2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}

   
