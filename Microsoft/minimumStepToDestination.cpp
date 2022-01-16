#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(int D)
    {
        // code here
        int steps = 0, sum = 0;
        while (true)
        {
            sum = sum + steps;
            steps++;
            if (sum == D)
            {
                return steps - 1;
                break;
            }
            if (sum > D and (sum - D) % 2 == 0)
            {
                return steps - 1;
                break;
            }
        }
        return 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int D;
        cin >> D;

        Solution ob;
        cout << ob.minSteps(D) << "\n";
    }
    return 0;
}