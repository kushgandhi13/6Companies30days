#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool winnerOfGame(string s)
    {
        int count = 0;
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i] == s[i - 1] && s[i] == s[i + 1])
                if (s[i] == 'A')
                    count++;
                else
                    count--;
        }

        if (count > 0)
            return true;
        return false;
    }
};