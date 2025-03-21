#include<iostream>
#include<vector>
#include<map>
#include<set>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string &s)
{

    int res = 0;

    unordered_map<char, int> m;
    int temp = 0;
    int lastIdx = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (m.find(s[i]) == m.end() || m[s[i]] < lastIdx)
        {
            m[s[i]] = i;
            temp++;
            res = max(temp, res);
        }
        else
        {
            temp = i - m[s[i]];
            lastIdx = i;
            res = max(res, temp);
            m[s[i]] = i;
        }
        // cout<<res<<" "<<temp<<" "<<i<<endl;
    }

    return res;
}

int main(){

    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}