#include <iostream>
#include <vector>

template <class T>
int binarySearch(std::vector<T>& A, T& K){
    int l = 0, m = 0, n = A.size();
    int r = n - 1;
    while (l <= r){
        m = (l+r)/2;
        if (K == A[m])
            return m;
        else if (K < A[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main() {
    std::vector<int> instances = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42};
    int key = 9;
    std::cout << "Index: " << binarySearch(instances, key);
    return 0;
}
