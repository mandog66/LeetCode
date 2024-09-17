#include <iostream>
#include <vector>

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
    int res = 0;

    void top_down(Node *node, int depth)
    {
        if (node->children.empty())
            res = std::max(res, depth);

        for (int i = 0; i < node->children.size(); i++)
            top_down(node->children[i], depth + 1);

        return;
    }

    int bottom_up(Node *node, int v)
    {
        if (node->children.empty())
            return v + 1;

        int n = 0;

        for (int i = 0; i < node->children.size(); i++)
            n = std::max(n, bottom_up(node->children[i], n));

        return n + 1;
    }

    int maxDepth(Node *root)
    {
        if (!root)
            return 0;

        // top_down(root, 1);
        // return res;
        return bottom_up(root, 0);
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
    std::cout << s.maxDepth(n1) << std::endl;
}