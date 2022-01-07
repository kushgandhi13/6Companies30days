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
    vector<int> ans;
    vector<int> serialize(Node *root)
    {
        if (!root)
            return ans;

        ans = serialize(root->left);
        ans.push_back(root->data);
        ans = serialize(root->right);

        return ans;
    }

    Node *deSerialize(vector<int> &v)
    {
        Node *newNode = new Node(-1);
        Node *temp = newNode;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            temp->right = new Node(v[i]);
            temp = temp->right;
        }

        return newNode->right;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node)
{
    if (node == NULL)
        return;

    _deleteTree(node->left);
    _deleteTree(node->right);

    delete node;
}

void deleteTree(Node **node_ref)
{
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        cout << "\n";
    }

    return 0;
}