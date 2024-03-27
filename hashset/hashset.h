#ifndef HASHSET_H
#define HASHSET_H
#include <vector>
#include <iostream>
using namespace std;

class hashset
{
private:
    struct node
    {
        node *next;
        int val;

        node() : val(-1), next(nullptr) {}
        node(int v) : val(v), next(nullptr) {}
    };

    vector<node *> bucket;

public:
    hashset();
    void add(int key);
    void remove(int key);
    bool contains(int key);
};
#endif