#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

class Solution
{
public:
    long long power(int n, int r)
    {
        if (r == 0)
            return 1;
        if (r == 1)
            return n;

        long long ans = power(n, r / 2) % mod;
        ans = (ans * ans) % mod;
        if (r & 1)
            return (n * ans) % mod;
        return ans % mod;
    }
};

long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    int T;
    cin >> T; // testcases

    while (T--)
    {
        long long N;
        cin >> N; // input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        // power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
} // } Driver Code Ends