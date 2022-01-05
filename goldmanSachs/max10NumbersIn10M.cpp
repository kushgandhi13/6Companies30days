#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking input

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    priority_queue<int> q;
    for (int i = 0; i < 10; i++)
        q.push(-v[i]);

    for (int i = 10; i < n; i++)
    {
        q.push(-v[i]);
        q.pop();
    }

    // to print max 10 elements
    while (!q.empty())
    {
        cout << (-1) * q.top() << " ";
        q.pop();
    }

    return 0;
}