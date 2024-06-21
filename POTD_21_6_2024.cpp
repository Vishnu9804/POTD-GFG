// POTD geeksforgeeks 21/06/2024
// Compare two fractions

#include <iostream>
#include <regex>
using namespace std;

class Solution
{
public:
    string compareFrac(string str)
    {
        int a, b, c, d;
        char slash1, slash2, comma;

        stringstream ss(str);
        ss >> a >> slash1 >> b >> comma >> c >> slash2 >> d;

        int lhs = a * d;
        int rhs = c * b;

        if (lhs > rhs)
        {
            return to_string(a) + "/" + to_string(b);
        }
        else if (lhs < rhs)
        {
            return to_string(c) + "/" + to_string(d);
        }
        else
        {
            return "equal";
        }
    }
};

int main()
{
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}
