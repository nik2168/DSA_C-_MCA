#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v = {1,2,3,4,5,6,7,8};

    int search;
    cout << "Enter ele to search : ";
    cin >> search;

    bool flag = false;
 
    int i = 0, e = v.size() - 1;

    while(i < e){
        int m = e - (i - e)/2;
        if(v[m] == search) flag = true;
        else if(v[m] > search) e = m - 1;
        else i = m + 1;
    }

    if (flag)
        cout << "Element is present in the array !";
    else
        cout << "Element is not present in the array !";

    return 0;
}

// output
// Enter ele to search : 3
// Element is not present in the array !%  