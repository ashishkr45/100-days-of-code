/*
char - occupies 1 byte(8 bits)
how do we storr char is by putting em btw single coutrs, ' '

what we can store,
    'a' to 'z'
    'A' to 'Z'
    '@', '$', '*'.... (special char)
    '0' - '9'

There all the char whixh we are using, all gets converted in bits(0 and 1) and
that encoding through which it's converted is caller
    ASCII(American Standrad Code for Information Interchange)
    ASCII is a 7 bit char stage where in total 128 char are there

*/

#include <iostream>
using namespace std;

int main()
{

    char ch = 'a', ch1 = 'z';
    char Ch = 'A', Ch1 = 'Z';

    cout << "ASCCI value of a: " << (int)ch << " and z: " << (int)ch1 << endl;
    cout << "ASCCI value of A: " << (int)Ch << " and Z: " << (int)Ch1 << endl;

    /*how to find the position of a char in the alphabet.*/
    // for example
    char sample = 'g';           // ascii value: 103
    int position = sample - 'a'; // 103(ascii of g) - 97(ascii of a) = 6(which is postion of g)
    /*a b c d e f g*/
    /*0 1 2 3 4 5 6*/
    cout << "Postion of g in alphabet: " << position << endl;

    return 0;
}