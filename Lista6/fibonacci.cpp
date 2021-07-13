#include <iostream>

int fibonacci(int n){
    int f;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    f = fibonacci(n - 1) + fibonacci(n - 2);
    return f;
}

int main() {
    int n = 10;
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    return 0;
}