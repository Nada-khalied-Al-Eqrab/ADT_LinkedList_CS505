//nada khaled Said- 2002400208
#include <iostream>
#include "list.h"
using namespace std;

int main()
{

    list nada;

    cout << "Insert opration:\n";
    nada.insertFirst(3, 'A');
    nada.insertFirst(1, 'B');
    nada.orderInsert(2, 'C');
    nada.orderInsert(5, 'D');
    nada.inserAfter(6, 'X');
    nada.traverse();
    cout << "\n ---------------------------------------" << endl;
    cout << "Search opration about key 2: ";
    if (nada.search(2))
        cout << "THE KEY IS FOUND"<< endl;
    else
        cout << "THE KEY IS NOT FOUND"<< endl;
    cout << "\n ---------------------------------------" << endl;
    cout << "Delete opration :" << endl;
    nada.deletefrist();
    nada.deletend();
    nada.traverse();
    cout << "\n ---------------------------------------" << endl;
    cout << "Make list empty opration:" << endl;
    nada.makelistempty();
    nada.traverse();
    cout << "the list is empty.";
    cout << "\n ---------------------------------------" << endl;

    return 0;
}
