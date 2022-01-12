// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Solution begins here : solve function and countSubtreesWithSumX
// Below are basic necessary functions provided by the editor on GFG.
int solve(Node *root, int x, int &count)
{
    if (!root)
        return 0;

    int temp1 = solve(root->left, x, count);
    int temp2 = solve(root->right, x, count);

    if (temp1 + temp2 + root->data == x)
        count++;
    return (temp1 + temp2 + root->data);
}

int countSubtreesWithSumX(Node *root, int x)
{
    if (!root)
        return 0;
    int count = 0;
    int temp = solve(root, x, count);
    return count;
}

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int countSubtreesWithSumX(Node *root, int x);

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        int x;
        cin >> x;
        getchar();
        cout << countSubtreesWithSumX(root, x) << endl;
    }
    return 0;
}
