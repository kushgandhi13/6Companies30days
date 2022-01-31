// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    int solve(Node *node)
    {
        if (!node)
            return 0;

        int left = solve(node->left);
        int right = solve(node->right);

        int temp = node->data;
        node->data = left + right;
        return temp + node->data;
    }

    void toSumTree(Node *node)
    {
        if (!node)
            return;

        solve(node);
    }
};
