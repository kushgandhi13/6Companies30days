// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    int minTime(Node *root, int target)
    {
        if (!root)
            return 0;
        // map<Node*,Node*>mp;
        vector<Node *> adj[10001];
        vector<bool> visited(10001, false);
        Node *start = NULL;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto temp = q.front();
                if (temp->data == target)
                    start = temp;
                q.pop();
                if (temp->left)
                {
                    adj[temp->data].push_back(temp->left);
                    adj[temp->left->data].push_back(temp);
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    // mp[temp->right] = temp;
                    adj[temp->right->data].push_back(temp);
                    adj[temp->data].push_back(temp->right);
                    q.push(temp->right);
                }
            }
        }

        if (start == NULL)
            return 0;

        queue<Node *> q2;
        swap(q, q2);
        q.push(start);
        visited[start->data] = true;
        int ans = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto temp = q.front();
                q.pop();
                for (auto x : adj[temp->data])
                {
                    if (!visited[x->data])
                    {
                        visited[x->data] = true;
                        q.push(x);
                    }
                }
            }
            if (size)
                ans++;
        }

        return ans - 1;
    }
};

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        int target;
        cin >> target;

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";
        cin.ignore();
    }

    return 0;
}
