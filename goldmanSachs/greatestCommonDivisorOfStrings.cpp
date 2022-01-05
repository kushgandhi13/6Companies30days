#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 + s2 != s2 + s1)
    {
        cout << " " << endl;
        return 0;
    }
    int n = s1.length();
    int m = s2.length();

    cout << s1.substr(0, __gcd(n, m)) << endl;

    return 0;
}