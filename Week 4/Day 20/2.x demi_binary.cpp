#include <iostream>
#include <string>
using namespace std;

void toBinary(int n);
void toDecimal(int n);
int reversr(int n);

int main()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    toBinary(num);

    return 0;
}

void toBinary(int n)
{
    int ans = 0;
    int power = 1;

    while (n > 0)
    {
        int remainder = n % 2;
        ans += remainder * power;
        n /= 2;
        power *= 10;
    }
    cout << "To binary: " << ans << endl;
    toDecimal(ans);
    return;
}

void toDecimal(int n)
{
    int power = 1;
    int ans = 0;
    string num = to_string(n);

    for (int i = num.size() - 1; i >= 0; i--)
    {
        ans += (num[i] - '0') * power;
        power *= 2;
    }
    cout << "To decimal: " << ans << endl;
    return;
}