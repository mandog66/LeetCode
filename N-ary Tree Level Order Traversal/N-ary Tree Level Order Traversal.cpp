#include <iostream>
#include <vector>
#include <queue>

using std::queue;
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
    queue<Node *> todo;
    vector<vector<int>> res;

    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};

        todo.push(root);

        while (!todo.empty())
        {
            vector<int> temp;
            int n = todo.size();

            for (int idx = 0; idx < n; idx++)
            {
                Node *curr = todo.front();

                todo.pop();

                for (int i = 0; i < curr->children.size(); i++)
                    todo.push(curr->children[i]);

                temp.push_back(curr->val);
            }

            res.push_back(temp);
        }

        return res;
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
    vector<vector<int>> res = s.levelOrder(n1);

    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "[" : ", [");
        for (int j = 0; j < res[i].size(); j++)
        {
            std::cout << (j == 0 ? "" : ", ") << res[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}