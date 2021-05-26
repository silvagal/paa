#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void firstPermutation(std::vector<T>& permutation, T &n){
    for (int i = 0; i < n; ++i)
        permutation.push_back(i + 1);
}

template <class T>
int largestConsecutiveIndex(std::vector<T>& a, bool& has_consecutive){
    int largest_value_idx = 0;
    has_consecutive = false;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] < a[i + 1]) {
            largest_value_idx = i;
            has_consecutive = true;
        }
    }
    return largest_value_idx;
}

template <class T>
int largestValueAhead(std::vector<T>& a, int& i){
    int largest_idx;
    for (int j = i + 1; j < a.size(); j++)
        if (a[i] < a[j])
            largest_idx = j;
    return largest_idx;
}

template <class T>
void swap(std::vector<T>& a, int& i, int& j){
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

template <class T>
void print(std::vector<T>& permutation){
    for (auto i : permutation)
        std::cout << i << " ";
    std::cout << std::endl;
}

template <class T>
void lexicographicPermute(T& n){
    int i = 0, j = 0, cont = 0;
    bool has_consecutive = true;
    std::vector<int> a;
    firstPermutation(a, n);
    std::cout << "[" << ++cont << "] ";
    print(a);
    i = largestConsecutiveIndex(a, has_consecutive);
    while (has_consecutive){
        j = largestValueAhead(a, i);
        swap(a, i, j);
        std::reverse(a.begin() + i + 1,a.end());
        std::cout << "[" << ++cont << "] ";
        print(a);
        i = largestConsecutiveIndex(a, has_consecutive);
    }
}

int main() {
    int n = 4;
    lexicographicPermute(n);
    return 0;
}
