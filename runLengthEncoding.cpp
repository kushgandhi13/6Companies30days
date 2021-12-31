// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this function */

string encode(string src)
{
    int k = 1;
    int n = src.length();
    string str = "";
    if (n == 1)
    {
        str += src[0];
        str += to_string(1);
        return str;
    }
    for (int i = 1; i < n; i++)
    {
        if (src[i] == src[i - 1])
            k++;
        else
        {
            str += src[i - 1];
            str += to_string(k);
            k = 1;
        }
    }

    str += src[n - 1];
    str += to_string(k);

    return str;
}
