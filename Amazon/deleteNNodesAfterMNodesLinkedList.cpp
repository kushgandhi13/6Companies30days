#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert(int n1)
{
    int n, value;
    n = n1;
    struct Node *temp;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

class Solution
{
public:
    void linkdelete(struct Node *head, int m, int n)
    {
        if (!head)
            return;
        Node *prev = NULL;

        while (head)
        {
            int p = m, q = n;
            while (p-- && head)
                prev = head, head = head->next;

            while (q-- && head)
            {
                if (!prev)
                {
                    Node *temp = head;
                    head = head->next;
                    temp->next = NULL;
                }
                else
                {

                    Node *temp = head->next;
                    head->next = NULL;
                    prev->next = temp;
                    head = prev->next;
                }
            }
        }

        return;
    }
};

int main()
{
    int t, n1;
    cin >> t;
    while (t--)
    {
        cin >> n1;
        int m, n;
        cin >> m;
        cin >> n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start, m, n);
        printList(start);
    }

    return 0;
}
