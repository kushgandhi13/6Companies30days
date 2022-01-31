#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct comp
    {
        bool operator()(const std::string &a, const std::string &b) const
        {
            if (a.size() != b.size())
                return a.size() < b.size();
            return a < b;
        }
    };

    string kthLargestNumber(vector<string> &nums, int k)
    {
        nth_element(nums.begin(), nums.end() - k, nums.end(), comp());
        return nums[nums.size() - k];
    }
};