#include <iostream>
#include <vector>
using namespace std;

int lastOccur(const vector<int> vec, int i, int target)
/*using const cuz, avoid copying the entire vector and to ensure the function does not modify the vector.*/
{
    if (vec[i] == target)
    {
        return i;
    }
    if (i < 0)
    {
        return -1;
    }

    return lastOccur(vec, i - 1, target);
}

int diffLastOccure(const vector<int> vec, int i, int target)
{
    if (i == (int)vec.size())
    {
        return -1;
        /*here when i will be equal to the vec.size the -1 will be returned
        which'll further will be assined the idxFound which sis further being checked
        in the if statement*/
    }

    int idxFound = diffLastOccure(vec, i + 1, target);

    if (idxFound == -1 && vec[i] == target)
    {
        return i;
    }

    return idxFound;
}

int main()
{
    vector<int> vec = {1, 2, 3, 3, 3, 4};
    cout << diffLastOccure(vec, 0, 3) << endl;
    return 0;
}