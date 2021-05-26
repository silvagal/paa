#include <iostream>
#include <vector>

template <class T>
int interpolationSearch(std::vector<T>& A, T& key){
    int low = 0;
    int high = A.size() - 1;
    int middle;

    while ( low <= high && key >= A[low] && key <= A[high]) {
        middle = low + ((key - A[low]) * (high - low) / (A[high] - A[low]));
        if (key < A[middle])
            high = middle - 1;
        else if (A[middle] < key)
            low = middle + 1;
        else
            return middle;
    }
    if (key == A[low])
        return low ;
    else
        return -1;
}

int main() {
    std::vector<int> instances = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42};
    int key = 21;
    std::cout << "Index: " << interpolationSearch(instances, key);
    return 0;
}
