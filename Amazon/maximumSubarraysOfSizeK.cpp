#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:
    
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> v;
        if (k == n)
        {
            int temp = *max_element(arr, arr + n);
            v.push_back(temp);
            return v;
        }

        priority_queue<pair<int, int>> q;

        for (int i = 0; i < k; i++)
            q.push({arr[i], i});

        int first = q.top().first;
        v.push_back(first);

        for (int i = k; i < n; i++)
        {
            q.push({arr[i], i});
            while (q.top().second <= i - k)
                q.pop();
            v.push_back(q.top().first);
        }

        return v;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} 