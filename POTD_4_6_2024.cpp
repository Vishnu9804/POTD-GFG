// POTD geeksforgeeks 04/06/2024
// Binary representation of next number

#include <bits/stdc++.h>
using namespace std;

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

class Solution
{
public:
    string binaryNextNumber(string s)
    {

        int i, l = s.size();

        string ans = "";
        for (i = l - 1; i >= 0; i--)
        {
            if (s[i] == '1')
                s[i] = '0';
            else
            {
                s[i] = '1';
                break;
            }
        }
        if (i < 0)
        {
            ans += '1';
            i = 0;
        }
        else
        {
            i = 0;
            while (s[i] == '0')
                i++;
        }
        ans += s.substr(i, l);

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
