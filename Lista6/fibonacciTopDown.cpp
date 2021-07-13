#include <iostream>
#include <vector>

int fibonacciTopDown(std::vector<int>& F, int n){
    if (F[n] != -1)
        return F[n];
    F[n] = fibonacciTopDown(F, n - 1) + fibonacciTopDown(F, n - 2);
    return F[n];
}

int main(){
    int n = 14;
    std::vector<int> F(n, -1);
    F[0] = 0;
    F[1] = 1;
    fibonacciTopDown(F, n - 1);
    for (auto i:F)
        std::cout << i << " ";
    return 0;
}