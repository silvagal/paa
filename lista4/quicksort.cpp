#include <iostream>
#include <vector>

using namespace std;

template <class T>
void swap(vector<T>& a, int& v1_idx, int& v2_idx){
    T aux = a[v1_idx];
    a[v1_idx] = a[v2_idx];
    a[v2_idx] = aux;
}

template <class T>
int hoarePartition(vector<T>& a, int& l, int& r){
    int p = a[l], i = l, j = r + 1;
    int g = 0;
    do{
        do {
            i = i + 1;
        }while(!(a[i] >= p));
        do {
            j = j - 1;
        }while(!(a[j] <= p));
        swap(a, i, j);
    }while(!(i >= j));
    swap(a, i, j);
    swap(a, l, j);
    return j;
}

template <class T>
void quickSort(vector<T>& a, int& l, int& r){
    if (l < r){
        int s = hoarePartition(a, l, r);
        int s1 = s - 1;
        int s2 = s + 1;
        quickSort(a, l, s1);
        quickSort(a, s2, r);
    }

}

int main() {
    vector<int> instances = {78, 9, 61, 75, 3, 6, 80, 8, 98, 53, 72, 21, 50, 25, 76, 96, 21,
                             98, 16, 72, 35, 91, 77, 33, 71, 27, 59, 100, 4, 4, 33, 56, 46,
                             77, 2, 61, 3, 77, 47, 80, 75, 5, 62, 1, 88, 18, 40, 32, 13, 72};

//    vector<char> instances = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int l = 0, r = instances.size() - 1;

    quickSort(instances, l, r);

    for (auto& i : instances)
        cout << i << " ";

    return 0;
}
