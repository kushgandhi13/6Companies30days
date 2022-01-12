#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
public:
    void solve(vector<string> &ans, int curIndex, int n, int a[], string str, vector<vector<char>> &mp)
    {
        if (curIndex == n)
        {
            ans.push_back(str);
            return;
        }
        for (auto x : mp[a[curIndex]])
        {
            str += x;
            solve(ans, curIndex + 1, n, a, str, mp);
            str.erase(str.end() - 1);
        }
    }

    vector<string> possibleWords(int a[], int n)
    {
        vector<string> ans;
        vector<vector<char>> mp(10);

        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        solve(ans, 0, n, a, "", mp);
        return ans;
    }
};

int main()
{

    int T;

    cin >> T;

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}