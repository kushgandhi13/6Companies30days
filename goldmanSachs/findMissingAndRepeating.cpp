#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int ans = 0, second = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
                arr[abs(arr[i]) - 1] *= -1;
            else
                second = abs(arr[i]);
        }
        int *a = new int[2];
        a[0] = second;
        // sum -= second;
        // int first = abs(n*(n+1)/2 - sum);
        for (int i = 0; i < n; i++)
            if (arr[i] > 0)
                a[1] = (i + 1);

        return a;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} 