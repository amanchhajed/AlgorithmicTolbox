#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
int get_fibonacci_partial_sum_fast(long long from, long long to) {
    from = fibonacci_sum_fast(from-1);
    to = fibonacci_sum_fast(to);
    return (10 + to - from)%10;

}
int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
