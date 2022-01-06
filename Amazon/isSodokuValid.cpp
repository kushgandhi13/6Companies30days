#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        vector<set<int>> rows(9), cols(9), blocks(9);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mat[i][j] == 0)
                    continue;

                int curr = mat[i][j];
                if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i / 3) * 3 + j / 3].count(curr))
                    return 0;

                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i / 3) * 3 + j / 3].insert(curr);
            }
        }

        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
}