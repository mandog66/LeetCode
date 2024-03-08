#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include <array>
#include <stack>
#include <sstream>

using namespace std;

class MyLinkedList
{
public:
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (index >= size || index < 0)
        {
            return -1;
        }
        else
        {
            Node *currentNode = head;

            for (int i = 0; i < index; i++)
            {
                currentNode = currentNode->next;
            }

            return currentNode->value;
        }
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
        {
            return;
        }

        Node *currentNode = head;
        Node *newNode = new Node(val);

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                currentNode = currentNode->next;
            }

            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }

        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }
        else if (index == 0)
        {
            Node *tempNode = head;
            head = head->next;
            delete tempNode;
        }
        else
        {
            Node *currentNode = head;
            for (int i = 0; i < index - 1; i++)
            {
                currentNode = currentNode->next;
            }

            Node *nextNode = currentNode->next->next;
            delete currentNode->next;
            currentNode->next = nextNode;
        }

        size--;
    }

    void showList()
    {
        Node *currentNode = head;
        for (int i = 0; i < size; i++)
        {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

private:
    struct Node
    {
        int value;
        Node *next;

        // 初始化參數
        // 當然也可以寫成建構子的樣子
        Node(int val) : value(val), next(nullptr) {}
    };

    Node *head;
    int size;
};

int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->showList(); // 1

    obj->addAtHead(2);
    obj->showList(); // 2 1

    obj->addAtTail(3);
    obj->showList(); // 2 1 3

    obj->addAtIndex(1, 2);
    obj->showList(); // 2 2 1 3

    obj->deleteAtIndex(1);
    obj->showList(); // 2 1 3
}
