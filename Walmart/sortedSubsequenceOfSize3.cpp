#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int n)
    {

        int x = INT_MAX;
        int y = INT_MIN;

        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            x = min(x, arr[l]);
            y = max(y, arr[r]);
            if (y > x)
            {
                for (int i = l + 1; i < r; i++)
                {
                    if (arr[i] < y && arr[i] > x)
                        return {x, arr[i], y};
                }
            }
            l++;
            r--;
        }
        return {};
    }
};