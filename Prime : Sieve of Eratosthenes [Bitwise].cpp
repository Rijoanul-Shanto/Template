/*
 * Rijoanul Hasan Shanto
 * Prime : Sieve of Eratosthenes [Bitwise]
 * Saturday, October 8, 2016
 * 07:27 pm
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 100001
using namespace std;

int prime[MAX];
int n = 1000000;

int set_bit(int n, int position)
{
    return (n | (1 << position));
}

bool check_bit(int n, int position)
{
    return (n & (1 << position));
}

void generate_prime()
{
    int i, j, k = sqrt(n);
    
    prime[0] = set_bit(prime[0], 0);
    prime[0] = set_bit(prime[0], 1);

    for(i = 4; i <= n; i += 2)
        prime[i >> 5] = set_bit(prime[i >> 5], i & 31);

    for(i = 3; i <= k; i += 2)
        if(!check_bit(prime[i >> 5], i & 31))
            for(j = i * i; j <= n; j += i + i)
                prime[j >> 5] = set_bit(prime[j >> 5], j & 31);
}

int main()
{
    generate_prime();
    int num;
    while(cin >> num)
    {
        if(!check_bit((prime[num >> 5]), num & 31))
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }

    return 0;
}

 
