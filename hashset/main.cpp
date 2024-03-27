#include <iostream>
#include "hashset.h"

using namespace std;

int main()
{
    hashset *myHashSet = new hashset();
    myHashSet->add(1);
    myHashSet->add(1001);
    myHashSet->add(2001);

    myHashSet->remove(2001);
    myHashSet->remove(1);

    if (myHashSet->contains(1))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    if (myHashSet->contains(3))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}