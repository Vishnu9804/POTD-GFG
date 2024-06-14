#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string armstrongNumber(int n)
    {
        if (n <= 0)
        {
            return "false";
        }

        int originalNum = n;
        int numberOfDigits = 0;
        while (originalNum > 0)
        {
            numberOfDigits++;
            originalNum /= 10;
        }

        int sum = 0;
        originalNum = n;
        while (originalNum > 0)
        {
            int digit = originalNum % 10;
            sum += pow(digit, numberOfDigits);
            originalNum /= 10;
        }

        return (sum == n) ? "true" : "false";
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}
