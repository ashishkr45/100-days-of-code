#include <iostream>
using namespace std;

int main()
{

    int a = 10; // this'll be stored in stack
    // compiler by default well store all the variable in stack.
    // memory allocation and deallocation is done automatacally be the compliler.

    int *p = new int(); // allocate memory in heap
    // it's also called dynamic memory allocation, in this it is up to us to store the variable.
    // it can be accessed from any where as long as we are having its address.
    *p = 10;

    delete (p); // deallocating the memory
    // since we are manually allocating the memory we'll also have to dealocate it manually.
    // here we have remove the varaiabe from the memory but the pointer is still there.
    // the pointer will be pointer to a adderess where nothing is stored which is also called, Dangaling Pointer.

    p = new int[4]; // creating a new array
    // now the pointer p is pointing to the first element of the array p.

    delete[] p; // deallocteing the memory

    p = NULL; // now the pointer is null its not pointing at anyting.

    return 0;
}