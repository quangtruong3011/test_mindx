#include <iostream>

using namespace std;

void sumOfDivisors(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    cout << sum;
};

int main()
{
    int n;
    cin >> n;
    sumOfDivisors(n);
    return 0;
}