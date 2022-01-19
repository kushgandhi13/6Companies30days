#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long atoi(string str)
    {
        int n = str.length();
        long long temp = 0;
        bool flag = false;

        if (str[0] == '-')
            flag = true;

        for (int i = 0; i < n; i++)
        {
            if (flag && i == 0)
                continue;
            if (isdigit(str[i]))
                temp = temp * 10 + (str[i] - '0');
            else
                return -1;
        }
        if (flag)
            temp *= -1;
        return temp;
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
        cout << ob.atoi(s) << endl;
    }
}