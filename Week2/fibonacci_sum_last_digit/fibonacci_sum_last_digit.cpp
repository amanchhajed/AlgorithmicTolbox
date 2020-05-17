#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if(n<=2)
      return n;
    int a0 = 1;
    int a1 = 2;
    while(n>2) {
        a1 = a1 + a0 + 1;
        a0 = a1 - a0 - 1;
        a1 = a1 % 10;
        a0 = a0 % 10;
        n--;
    }
    return a1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
