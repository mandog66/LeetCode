#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> res;
    stack<Node *> todo;

    void helper(Node *node)
    {
        int n = node->children.size();

        for (int i = 0; i < n; i++)
        {
            Node *temp = node->children[i];

            helper(temp);
        }

        res.push_back(node->val);
    }

    vector<int> postorder(Node *root)
    {
        if (!root)
            return {};

        helper(root);

        return res;
    }

    vector<int> postorder_iterative(Node *root)
    {
        todo.push(root);

        while (!todo.empty())
        {
            Node *temp = todo.top();
            todo.pop();

            for (int i = 0; i < temp->children.size(); i++)
                todo.push(temp->children[i]);

            res.push_back(temp->val);
        }

        return vector<int>(res.rbegin(), res.rend());
    }
};

int main(int argc, char *argv[])
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
    Node *n10 = new Node(10);
    Node *n11 = new Node(11);
    Node *n12 = new Node(12);
    Node *n13 = new Node(13);
    Node *n14 = new Node(14);

    n1->children = {n2, n3, n4, n5};
    n3->children = {n6, n7};
    n4->children = {n8};
    n5->children = {n9, n10};
    n7->children = {n11};
    n8->children = {n12};
    n9->children = {n13};
    n11->children = {n14};

    Solution s;
    for (auto n : s.postorder_iterative(n1))
        std::cout << n << " ";
    std::cout << std::endl;
}