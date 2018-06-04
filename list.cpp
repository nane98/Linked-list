#include <iostream>
using namespace std;
#include "list.h" 
int main()
{
    LinkedList<int> ob;
    ob.insert(2);
    ob.insert(5);
    ob.insert(3, 0);
    ob.insert(4);
    ob.print();
    ob.empty();
    ob.insert(20);
    ob.insert(5, 1);
    ob.insert(3);
    ob.print();
    ob.remove();
    ob.print();
}
