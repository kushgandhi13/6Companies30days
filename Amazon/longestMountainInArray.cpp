#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int count = 0;
        int n = arr.size();
        if (n <= 2)
            return 0;
        int low = -1, high = -1, next = -1;
        for (int i = 0; i < n; i++)
        {
            if (low == -1)
                low = i;
            else
            {
                if (arr[i] > arr[i - 1] && next == -1)
                    high = i;
                else if (arr[i] > arr[i - 1])
                {
                    next = -1;
                    low = i - 1;
                    high = i;
                }
                else if (arr[i] < arr[i - 1] && high != -1)
                {
                    next = i;
                    count = max(count, next - low + 1);
                }
                else
                {
                    low = i, high = -1, next = -1;
                }
            }
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        // cin >> K;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.longestMountain(A) << endl;
    }
    return 0;
}