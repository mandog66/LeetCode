#include <iostream>
#include <queue>

using std::queue;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (!root)
        return nullptr;

    queue<Node *> todo;
    todo.push(root);

    while (!todo.empty())
    {
        int n = todo.size();

        for (int i = 0; i < n; i++)
        {
            Node *cur = todo.front();
            todo.pop();

            if (cur->left)
                todo.push(cur->left);

            if (cur->right)
                todo.push(cur->right);

            cur->next = (i != n - 1) ? todo.front() : nullptr;
        }
    }

    return root;
}

int main(int argc, char *argv[])
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    connect(n1);
}