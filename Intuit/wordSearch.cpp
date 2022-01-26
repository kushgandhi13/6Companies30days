#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, int n, int m, string word, int curIndex)
    {
        if (curIndex >= word.length())
            return true;

        int x[] = {0, 0, -1, 1};
        int y[] = {-1, 1, 0, 0};

        for (int k = 0; k < 4; k++)
        {
            int xx = x[k] + i;
            int yy = y[k] + j;
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy])
            {
                // visited[xx][yy] = true;
                if (board[xx][yy] == word[curIndex])
                {
                    visited[xx][yy] = true;
                    if (dfs(board, visited, xx, yy, n, m, word, curIndex + 1))
                        return true;
                    visited[xx][yy] = false;
                }
            }
        }
        return false;
    }

    bool isWordExist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int curIndex = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[curIndex])
                {
                    visited[i][j] = true;
                    if (dfs(board, visited, i, j, n, m, word, curIndex + 1))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> board[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(board, word);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}