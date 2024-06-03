// POTD geeksforgeeks 31/05/2024
// Swap two nibbles in a byte

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
    int swapNibbles(int n)
    {
        int leftNibble = (n & 0xF0) >> 4;
        int rightNibble = (n & 0x0F) << 4;
        return (rightNibble | leftNibble);
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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
