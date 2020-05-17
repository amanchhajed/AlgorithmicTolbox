#include <iostream>
#include <cmath>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
void populateLasDigit(int* arr) {
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<60;i++) {
        arr[i] = (arr[i-1] + arr[i-2])%10;
    }
}
int main() {
    int n;
    int arr[60];
    populateLasDigit(arr);
    std::cin >> n;
    int c = arr[n%60];
    std::cout << c << '\n';
}
