/*
In this question we are pairing people, total numbers: n
    One can be by himself then, remanining are (n-1)
    or, they can get paired with a other guy then, remaining are, (n-2)

recurance relation for this'll be:
    f(n) = f(n-1) + (n-1) * f(n-2)

for example:
    let say ther are 3: A B C
        i) A can be with himself
        ii) A can be with
*/

#include <iostream>
using namespace std;

int pairing(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return pairing(n - 1) + ((n - 1) * pairing(n - 2));
}