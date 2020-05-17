#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long getPisanoPeriod(long long m) {
    long long a0 = 0;
    long long a1 = 1;
    long long pisano = 0;
    while(true) {
        pisano += 1;
        a1 = a1 + a0;
        a0 = a1 - a0;
        a1 = a1 % m;
        a0 = a0 % m;
        if(a1 == 1 && a0 == 0)
          return pisano;
    }
}
long long getFibonacciModuleM(long long n, long long m) {
    long long pisano = getPisanoPeriod(m);
    n = n%pisano;
    if(n <= 1)
      return n;
    long long a0 = 0;
    long long a1 = 1;
    while(n>1) {
        a1 = a1 + a0;
        a0 = a1 - a0;
        a1 = a1 % m;
        a0 = a0 % m;
        n--;
    }
    return a1;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << getFibonacciModuleM(n, m) << '\n';
    return 0;
}
