#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *DFS(Node *cur, unordered_map<Node *, Node *> &mp)
{
    vector<Node *> newNeighbor;
    Node *newNode = new Node(cur->val);
    mp[cur] = newNode;

    for (auto neighbor : cur->neighbors)
    {
        if (mp.find(neighbor) != mp.end())
        {
            newNeighbor.push_back(mp[neighbor]);
        }
        else
        {
            newNeighbor.push_back(DFS(neighbor, mp));
        }
    }

    newNode->neighbors = newNeighbor;
    return newNode;
}

Node *cloneGraph(Node *node)
{
    unordered_map<Node *, Node *> mp;

    if (node == NULL)
        return NULL;

    if (node->neighbors.size() == 0)
    {
        Node *newNode = new Node(node->val);
        return newNode;
    }

    return DFS(node, mp);
}

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n1->neighbors = {n2, n3, n4};
    n2->neighbors = {n1, n3, n4};
    n3->neighbors = {n1, n2, n4};
    n4->neighbors = {n1, n2, n3};

    cout << cloneGraph(n1)->val << endl;

    return 0;
}