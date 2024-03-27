#include "hashset.h"

hashset::hashset()
{
    bucket = vector<node *>(1000);
}
void hashset::add(int key)
{
    int hashValue = key % 1000;
    node *newNode = new node(key);

    if (!bucket[hashValue])
    {
        bucket[hashValue] = newNode;
    }
    else if (!contains(key))
    {
        node *head = bucket[hashValue];
        while (head->next)
        {
            head = head->next;
        }

        head->next = newNode;
    }
    else
    {
        cout << "already exist" << endl;
    }
}
void hashset::remove(int key)
{
    if (contains(key))
    {
        int hashValue = key % 1000;
        node *prev = bucket[hashValue];

        if (bucket[hashValue]->val == key)
        {
            bucket[hashValue] = bucket[hashValue]->next;
            return;
        }

        for (auto _node = bucket[hashValue]; _node;)
        {
            if (_node->val == key)
            {
                node *temp = _node;
                prev->next = _node->next;
                delete temp;
                break;
            }
            else
            {
                if (_node != bucket[hashValue])
                    prev = prev->next;
                _node = _node->next;
            }
        }
    }
    else
    {
        cout << "not exist" << endl;
    }
}
bool hashset::contains(int key)
{
    int hashValue = key % 1000;
    node *head = bucket[hashValue];

    for (auto node = head; node;)
    {
        if (node->val == key)
            return true;
        else
            node = node->next;
    }

    return false;
}
