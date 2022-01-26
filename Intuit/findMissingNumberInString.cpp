#include <bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string &str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << missingNumber(str) << endl;
    }
    return 0;
}

int solve(const string &str, int startIndex, int len)
{
    if (startIndex + len > str.length())
        return -1;

    int num = 0;
    for (int j = 0; j < len; j++)
        num = num * 10 + (str[startIndex + j] - '0');

    return num;
}

int missingNumber(const string &str)
{
    for (int len = 1; len <= 6; len++)
    {
        int num = solve(str, 0, len);

        if (num == -1)
            break;
        int missingNum = -1;
        bool temp = true;

        for (int i = len; i != str.length(); i += 1 + log10l(num))
        {
            if (missingNum == -1 && solve(str, i, 1 + log10l(num + 2)) == num + 2)
            {
                missingNum = num + 1;
                num += 2;
            }
            else if (solve(str, i, 1 + log10l(num + 1)) == num + 1)
                num++;
            else
            {
                temp = false;
                break;
            }
        }

        if (temp)
            return missingNum;
    }

    return -1;
}