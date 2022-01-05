// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i] % k]++;

        if (mp[0] & 1)
            return false;

        int l = 1, r = k - 1;
        while (l <= r)
        {
            if (mp[l] == mp[r])
                l++, r--;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}