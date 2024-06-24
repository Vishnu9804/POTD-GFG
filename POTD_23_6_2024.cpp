// POTD geeksforgeeks 23/05/2024
// Print Bracket Number

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        vector<int> result;
        stack<int> stk;
        int counter = 1;

        for (char ch : str)
        {
            if (ch == '(')
            {
                result.push_back(counter);
                stk.push(counter);
                counter++;
            }
            else if (ch == ')')
            {
                if (!stk.empty())
                {
                    result.push_back(stk.top());
                    stk.pop();
                }
            }
        }

        return result;
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

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
