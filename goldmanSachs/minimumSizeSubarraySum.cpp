#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target; // n = number of elements in the array;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int l = 0, r = 0;
    int ans = INT_MAX;
    int sum = 0;
    while (l < n)
    {
        if (sum + nums[l] < target)
            sum += nums[l++];
        else
        {
            // cout<<sum<<" "<<l<<" "<<r<<endl;
            sum += nums[l];

            while (sum >= target && r < n)
            {
                ans = min(ans, l - r + 1);
                sum -= nums[r++];
            }
            l++;
        }
    }
    // ans = min(ans,l-r-1);
    if (ans == INT_MAX)
        return 0;
    return ans;
}