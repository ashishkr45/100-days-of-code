#include <iostream>
#include <list>
#include <iterator>
/*iterators will help us in the printing of the linked List we created from stl*/

using namespace std;

void printList(list<int> linked)
{
    list<int>::iterator itr;

    for (itr = linked.begin(); itr != linked.end(); itr++)
    {
        cout << (*itr) << "->";
    }
    cout << "NULL" << endl;
}

int main()
{
    list<int> linked;
    linked.push_front(69);
    linked.push_front(45);
    linked.push_front(23);

    linked.push_back(88); // 23->45->69->88
    printList(linked);

    cout << "Size of linked list: " << linked.size() << endl;
    cout << "Head value: " << linked.front() << endl;
    cout << "Tail value: " << linked.back() << endl;

    return 0;
}