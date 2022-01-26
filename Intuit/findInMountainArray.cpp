#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &a)
    {
        int n = a.length();
        int l = 0, r = n - 1, peak;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (a.get(mid) < a.get(mid + 1))
                l = peak = mid + 1;
            else
                r = mid;
        }

        l = 0, r = peak;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a.get(mid) == target)
                return mid;
            else if (a.get(mid) < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        l = peak, r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a.get(mid) == target)
                return mid;
            else if (a.get(mid) < target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
};