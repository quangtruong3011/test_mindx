#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> superPrimeNumber(int n)
{
    queue<int> prime_queue;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            prime_queue.push(i);
        }
    }

    vector<int> sort_super_prime;
    while (!prime_queue.empty())
    {
        sort_super_prime.push_back(prime_queue.front());
        prime_queue.pop();
    }

    return sort_super_prime;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sort_super_prime = superPrimeNumber(n);

    for (int prime : sort_super_prime)
    {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}