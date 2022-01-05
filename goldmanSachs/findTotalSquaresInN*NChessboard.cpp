#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n; // size of chessboard
    cout << ((n) * (2 * n + 1) * (n + 1)) / 6;
    return 0;
}