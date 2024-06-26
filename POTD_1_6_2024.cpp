// POTD geeksforgeeks 01/06/2024
// Odd Even Problem

#include <bits/stdc++.h>

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

using namespace std;

class Solution
{
public:
    string oddEven(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        int x = 0, y = 0;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                int pos = i + 1;
                if (pos % 2 == 0)
                {
                    if (freq[i] % 2 == 0)
                    {
                        x++;
                    }
                }
                else
                {
                    if (freq[i] % 2 == 1)
                    {
                        y++;
                    }
                }
            }
        }

        int sum = x + y;
        if (sum % 2 == 0)
        {
            return "EVEN";
        }
        else
        {
            return "ODD";
        }
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}
