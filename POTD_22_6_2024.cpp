// POTD geeksforgeeks 22/06/2024
// Extract the Number from the String

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
    long long ExtractNumber(string sentence)
    {
        istringstream iss(sentence);
        string word;
        long long maxNumber = -1;

        while (iss >> word)
        {
            bool isNumber = true;
            for (char ch : word)
            {
                if (!isdigit(ch))
                {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber)
            {
                long long num = stoll(word);
                if (word.find('9') == string::npos)
                {
                    if (num > maxNumber)
                    {
                        maxNumber = num;
                    }
                }
            }
        }
        return maxNumber;
    }
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}
