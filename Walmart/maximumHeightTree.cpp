#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int height(int n)
    {
        return (int)(-1 + pow(1 + 8 * n, 0.5)) / 2;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.height(N) << endl;
    }
    return 0;
}