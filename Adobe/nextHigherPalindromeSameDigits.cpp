#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string nextPalin(string str)
    {
        map<int, int> mp;
        int n = str.length();
        for (int i = 0; i < n; i++)
            mp[str[i] - '0']++;

        int pos = -1;
        int final;
        if (n & 1)
            final = (n / 2) - 1;
        else
            final = n / 2;

        for (int i = 0; i < final; i++)
        {
            if (str[i] < str[i + 1])
                pos = i;
        }
        if (pos == -1)
            return "-1";

        for (int i = 0; i < pos; i++)
            mp[str[i] - '0'] -= 2;

        string temp = str.substr(0, pos);

        int num = str[pos] - '0';
        num++;
        while (mp[num] < 2)
            num++;
        temp += to_string(num);
        mp[num] -= 2;
        for (int i = 0; i < 10; i++)
            while (mp[i] >= 2)
            {
                temp += to_string(i);
                mp[i] -= 2;
            }

        string ans = temp;
        reverse(ans.begin(), ans.end());
        if (n & 1)
            return temp + str[n / 2] + ans;
        return temp + ans;
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
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}