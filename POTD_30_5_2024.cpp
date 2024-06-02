#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(string s1, string s2)
    {
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}